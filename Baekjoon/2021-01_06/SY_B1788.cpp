/*
백준 1788번 피보나치 수의 확장
*/

#include <iostream>
#define mod 1000000000
using namespace std;

int dp[1000001]={0,1,0};

int main(){
    int input;
    int index;
    cin >> input;
    if(input<0)
    {
        index = input *(-1);
    }
    else
    {
        index = input;
    }
    if(index == 0 )
    {
        cout << 0;
        cout << "\n";
        cout << 0;
        return 0;
    }
    for(int i = 2; i <= index; i++){
        dp[i] = (dp[i-1] + dp[i-2]) % mod;
    }
    dp[index] = dp[index] % mod;
    if(input < 0)//음수의 경우
    {
        if(index % 2 == 0)
        {
            cout << -1;
            cout << "\n";
            cout << dp[index];
            return 0;
        }
    }
    
    cout << 1;
    cout << "\n";
    cout << dp[index];
    

    return 0;
}