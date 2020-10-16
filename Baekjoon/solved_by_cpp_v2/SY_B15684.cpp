/*
백준 - B15684 : 
solved by SY
DFS 넣다 뺏다 스타일
마지막에 cout << ?:  스타일 되는 줄 알았다가 1시간 고생했다...
맨앞에 조건문 결과가 출력되는 희대의 사건이 벌어졌다.
ㄹㅈㄷ
DATE : 2020.10.16
*/
#include <iostream>
#define min(a,b) a<b?a:b
using namespace std;
int map[32][12];
int N, M, H;
int INF = 2e9;
int ans = INF;
bool check(){
    for(int i = 1; i<=N;i++){
        int c = i;
        for(int j = 1; j<=H;j++){
            if(map[j][c]==1) c=c+1;
            else if(map[j][c-1]==1) c=c-1;
        }
        if(c!=i)return false;
    }
    return true;
}
void solve(int sr, int cnt){
    if(check()) {ans = min(cnt,ans); return;}
    if(cnt == 3) return;
    for(int r = sr; r <=H; r++){
        for(int c = 1; c < N;c++){
            if(map[r][c]==1) continue;
            if(map[r][c-1]==1) continue;
            if(map[r][c+1]==1) continue;
            map[r][c] = 1;
            solve(r,cnt+1);
            map[r][c] = 0; 
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> N>> M>> H;
    for(int i = 0; i< M;i++){
        int r,c;
        cin >> r >> c;
        map[r][c]=1;
    }
    solve(1,0);
    if(ans == INF){cout << -1; return 0;}
    cout << ans; 
    /*
    이딴 코드 다시는 쓰지 말 것.
    cout << (ans==INF)?-1:ans; 
    */
   return 0;
}