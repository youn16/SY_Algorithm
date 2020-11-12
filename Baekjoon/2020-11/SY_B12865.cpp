#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int N,K;
int dp[101][100001];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin >> N >> K;
    vector<pair<int,int>> input;//무게, 가치
    input.push_back(make_pair(0,0));
    for(int i = 0; i < N; i++){
        int weigh, val;
        cin >> weigh >> val;
        input.push_back(make_pair(weigh,val));
    }
    for(int i = 1; i <= N; i++){
        for(int g = 1; g <= K; g++){
            dp[i][g] = dp[i-1][g];
            if(input[i].first<=g){
                dp[i][g] = max(dp[i][g],dp[i-1][g-input[i].first]+input[i].second);
            }
        }
    }
    cout << dp[N][K];
    return 0;
}