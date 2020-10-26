/*
백준 - B11723 : 집합
solved by SY
비트마스크
DATE : 2020.10.08
*/
#include <iostream>
#include <string>
#define ui unsigned int

using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n = 0;
    cin >> n;
    ui res = 0;
    for(int k = 0; k<n;k++){
        string s;
        ui m = 0;
        cin >> s;
        if(s == "add"){
            cin >> m;
            res |= (1<<m);
        }else if(s == "remove"){
            cin >> m;
            res &= ~(1<<m);
        }else if(s == "check"){
            cin >> m;
            if(res & (1<<m)){cout << 1<<"\n";}
            else{cout << 0 <<"\n";}
        }else if(s == "toggle"){
            //S에 x가 있으면 x를 제거하고, 없으면 x를 추가한다. (1 ≤ x ≤ 20)
            cin >> m;
            res ^= (1<<m);
        }else if(s == "all"){
            for(int i = 1; i<=20;i++){
                res |= (1<<i);
            }
        }else if(s == "empty"){
            res = 0;
        }
    }
    return 0;
}