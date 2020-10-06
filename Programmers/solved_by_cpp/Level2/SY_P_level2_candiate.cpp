#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int countBits(int n)
{
    int ret = 0;
    while (n)
    {
        if (n & 1) ret++;
        n = n >> 1;
    }
    return ret;
}

bool cmp(int a, int b)
{
    //���� ��Ʈ�� ī��Ʈ
    int x = countBits(a), y = countBits(b);
    return x > y;//�������� ����
}
bool check(vector<vector<string>> relation,int low, int col,int bit) {

    for (int i = 0; i < low - 1;i++) {
        for (int j = i+1; j < low;j++) {
            int issame = true;
            for (int k = 0; k < col;k++) { //���� �� �Ұ�.
                if ((bit & (1 << k)) == 0) { continue; }
                if (relation[i][k] != relation[j][k]) { issame = false; break; }
            }
            if (issame) { return false; }
        }
    }
    return true;
}

int solution(vector<vector<string>> relation)
{
    int answer = 0;
    int col = relation[0].size();
    int low = relation.size();
    vector<int> v;

    for (int i = 1; i < (1 << col); i++) {
        if (check(relation, low, col, i)) { v.push_back(i); }
    }
    sort(v.begin(), v.end(), cmp);
    while (!v.empty())
    {
        int n = v.back();//1�� ������ ���� ����������
        v.pop_back();
        answer++;

        //���ϼ� üũ
        for (vector<int>::iterator it = v.begin(); it != v.end(); )
        {
            if ((n & *it) == n)
                it = v.erase(it);
            else it++;
        }
    }
    return answer;
}

int main() {
    vector<vector<string>> relation = {
        {"100","ryan","music","2"} ,
        {"200","apeach","math","2"},
        {"300","tube","computer","3"},
        {"400","con","computer","4"},
        {"500","muzi","music","3"},
        {"600","apeach","music","2"}
    };
    solution(relation);
    return 0;
}