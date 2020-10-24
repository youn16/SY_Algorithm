/*
백준 - B1712 : 손익분기점
solved by SY
수학
DATE : 2020.10.25
*/
#include <iostream>
#define ll long long

using namespace std;

int main(){
    ll A,B,C;
    cin >> A >> B >> C;
    ll res = 0;
    if(C<=B) cout << -1;
    else{
        res = (A/(C-B))+1;
        cout << res;
    } 
    return 0;
}