/*
백준 - B2884 : 알람시계
solved by SY
단순 구현
DATE : 2020.10.08
*/
#include <iostream>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int h,m;
    cin >> h >> m;
    m -= 45;
    if(m<0){
        h -= 1;
        m += 60;        
    }
    if(h<0) h+=24;
    cout << h <<" "<<m;
    return 0;
}