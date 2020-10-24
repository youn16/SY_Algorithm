/*
백준 - B1085 : 직사각형에서 탈출
solved by SY
수학
DATE : 2020.10.07
*/
#include <iostream>
#define min(a,b) a<b?a:b
#define abs(a) a>0?a:-a

using namespace std;
int main(){
    int x,y,w,h;
    cin >> x>>y>>w>>h;
    int res = min(x,y);
    int tmp = abs((x-w));
    res = min(res,tmp);
    tmp = abs((y-h));
    res = min(res,tmp);
    cout << res;
    return 0;
}