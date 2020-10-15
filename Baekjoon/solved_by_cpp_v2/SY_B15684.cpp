/*
백준 - B15684 : 
solved by SY
DFS
다른 분의 코드를 참고해서 풀었다. 다시 한번 풀어볼것!
DATE : 2020.10.15
*/
#include <iostream>
#define min(a,b) a<b?a:b
using namespace std;
int map[8][8];
int look[6][4] = {{},{0},{1,3},{0,1},{0,1,3},{0,1,2,3}};
int round[6] = {0,4,2,4,4,1};
int cnt[6] = {0,1,2,2,3,4};
int dr[4] = {-1,0,1,0};
int dc[4] = {0, 1, 0,-1};
int n,m;
int sum(){
    int res = 0;
    for(int i =0; i<n;i++){
        for(int j =0; j<m;j++){
            if(map[i][j]==0)
                res += 1;
        }
    }
    return res;
}
int dfs(int r, int c){
    int res = 2e9;
    if(r==n){
        return sum();
    }
    int next[2] = {r,c+1};
    if(next[1]==m){
        next[0]++;
        next[1]=0;
    }
    if(map[r][c]>0&&map[r][c]!=6){
        int cctv = map[r][c];
        for(int i = 0; i<round[cctv];i++){
            for(int t = 0; t<cnt[cctv];t++){
                int dir = (i+look[cctv][t])%4;
                int nr = r, nc = c;
                while(nr < n && nc< m && nr >= 0 && nc >= 0){
                    if(map[nr][nc] == 6) break;
 
                    if(map[nr][nc] <= 0){
                        map[nr][nc]--;
                    }
                    nr+= dr[dir];
                    nc+= dc[dir];
                }
            }
            res = min(res, dfs(next[0],next[1]));
            for(int t = 0; t<cnt[cctv];t++){
                int dir = (i+look[cctv][t])%4;
                int nr = r, nc = c;
                while(nr < n && nc< m && nr >= 0 && nc >= 0){
                    if(map[nr][nc] == 6) break;
                    if(map[nr][nc] < 0){
                        map[nr][nc]++;
                    }
                    nr+= dr[dir];
                    nc+= dc[dir];
                }
            }
        }
    }
    else{
        res = dfs(next[0],next[1]);
    }
    return res;
}
int main(){
    cin >> n >> m;
    for(int i =0; i<n;i++){
        for(int j = 0; j<m;j++){
            cin >> map[i][j];
        }
    }
    cout << dfs(0,0);
    return 0;
}