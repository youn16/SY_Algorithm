#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> words, vector<string> queries) {
    vector<int> answer;
    for (int i = 0; i < queries.size(); i++) {
        int res = 0;
        for (int j = 0; j < words.size(); j++) {
            if (queries[i].size() == words[j].size()) {
                bool flg = true;
                for (int k = 0; k < queries[i].size(); k++) {
                    if (queries[i][k] != '?' && queries[i][k] != words[j][k]) {
                        flg = false; break;
                    }
                }
                if (flg) { res++; }
            }
        }
        answer.push_back(res);
    }
    return answer;
}