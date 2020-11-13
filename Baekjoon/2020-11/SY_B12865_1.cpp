/*
가방 용량만으로 구하는 방법, 배열 [101][100001] -> [100001]로!
*/
#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;

int n,k;
int d[100001];  // 가방 용량
int w[101];     // 물건의 무게
int v[101];     // 물건의 가치

void dp(){
    for(int i=1; i<=n; i++){
        for(int j=k; j>=1; j--){
            /*
            k는 마지막
            이전 아이템 순서의 내용을 저장해 두지 않음으로,
            k에서 1이 아닌 1에서 k순으로 for문을 돌면, 앞에 사용된 내용이 중복으로 계산된다.
            냅색 문제 기본 표를 잘 떠올려 볼 것.
            */
            if(w[i] <= j){
                d[j] = max(d[j], d[j-w[i]] + v[i]);
            }
        }
    }
    
    cout << d[k] << "\n";
}

int main(int argc, const char * argv[]) {
    // cin,cout 속도향상
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> n >> k;
    for(int i=1; i<=n; i++){
        cin >> w[i] >> v[i];
    }
    
    dp();
    
    return 0;
}