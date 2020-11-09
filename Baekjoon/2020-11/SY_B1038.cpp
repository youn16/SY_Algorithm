#include <iostream>
#define ll long long
using namespace std;
ll res[1000001];
int main(){
    int cnt = 9;
    int input = 0;
    cin >> input;
    for(int i = 0; i < 10; i++){
        res[i] = i;
    }
    if(input < 10) {cout << res[input]; return 0;}
    int cur = 1;
    while(true){
        int val = res[cur]%10;
        for(int i = 0; i < val; i++){
            ll tmp = res[cur]*10+i;
            cnt++;
            if(cnt>1000000){break;}
            if(tmp>9876543210){res[cnt]=-1;}
            else{res[cnt] = tmp;}
        }
        if(cnt>=input){cout << res[input]; return 0;}
        else if(cur>=1000000||cnt>=1000000){cout << -1; return 0;}
        cur++;
    }
    return 0;
}