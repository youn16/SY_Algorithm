/*
백준 - B19237 : 스타트 택시
solved by SY
시뮬
DATE : 2020.10.16
*/
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int N,M;
long long Fuel;
int map[21][21];
int start[21][21];
vector<int> dep[21][21];
int dr[4] = {-1,0,0,1};
int dc[4] = {0,-1,1,0};
int fr,fc;
struct INFO
{
    int r;
    int c;
    int Dist;
    int Num;
};
bool cmp(INFO a, INFO b){
    if(a.Dist<b.Dist)return true;
    if(a.Dist==b.Dist){
        if(a.r<b.r) return true;
        if(a.r==b.r){
            if(a.c<b.c) return true;
        }
    }
    return false;
}
int path(int R,int C, int flg){
    int visit[21][21] = {0,};
    queue<pair<int, int> > q;
    visit[R][C] = 1;
    q.push(make_pair(R,C));
    vector<INFO> in;
    while(!q.empty()){
        int sr = q.front().first;
        int sc = q.front().second;
        if(flg == -1){
            if(start[sr][sc]!=0){
                in.push_back({sr,sc,visit[sr][sc]-1,start[sr][sc]});
            }
        }else{
            if(!dep[sr][sc].empty())
            for(int i =0;i<dep[sr][sc].size();i++){
                if(dep[sr][sc][i]==flg){
                fr = sr;fc = sc;
                return visit[sr][sc]-1;
                }
            }
        }
        q.pop();
        for(int i = 0; i<4; i++){
            int nr = sr+dr[i];
            int nc = sc+dc[i];
            if(nr<1 || nr>N || nc <1 || nc>N) continue;
            if(visit[nr][nc]==0 && map[nr][nc]==0){
                visit[nr][nc] = visit[sr][sc]+1;
                q.push(make_pair(nr,nc));
            }
        }
    }
    if(in.empty()) return -1;
    sort(in.begin(),in.end(),cmp);
    fr = in[0].r;fc = in[0].c;
    return in[0].Dist;
}
int solve(int sr, int sc){
    for(int i = 1; i<=M;i++){
        int cost = path(sr,sc,-1);
        if((Fuel-=cost) < 0 || cost ==-1) return -1;
        sr = fr; sc = fc;

        int costb = path(sr,sc,start[sr][sc]);
        if((Fuel-=costb) < 0 || costb==-1) return -1;
        start[sr][sc] = 0;
        sr = fr; sc = fc;
        Fuel += (costb*2);
    }
    return Fuel;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>> N >> M>> Fuel;
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N;j++){
            cin >> map[i][j];
        }
    }
    int sr,sc;
    cin >> sr >> sc;    
    for(int i = 1; i <= M; i++){
            int a,b,c,d;
            cin >> a>> b>> c>> d;
            start[a][b] = i;
            dep[c][d].push_back(i);
    }

    cout << solve(sr,sc);
    return 0;
}