/*
백준 - B2293 : 동전 1
solved by SY
동적 계획법
DATE : 2020.10.25
*/
#include <iostream>
using namespace std;

int dp[10001];
int cost[101];
int main(){
    int n,k;
    cin >> n >> k;
    for(int i = 0; i < n; i++) cin >> cost[i];
    dp[0] = 1;
    for(int i = 0; i < n; i++){
        for(int t = cost[i]; t<=k; t++){
            dp[t] += dp[t-cost[i]]; 
        }
    }
    cout << dp[k];
    return 0;
}