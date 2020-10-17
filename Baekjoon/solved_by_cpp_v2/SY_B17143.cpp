/*
백준 - B17143 : 낚시왕
solved by SY
시뮬, 법칙 찾기
되돌아오는 법칙 찾기가 아주 신박..
DATE : 2020.10.17
*/
#include <iostream>
#include <cstring>
#include <map>
using namespace std;
int mp[101][101];
struct shark{
    int r;
    int c;
    int speed;
    int dir;
    int size;
    bool live = false;
};
int dr[5] = {0,-1,1,0,0}; //위,아래,오른쪽,왼쪽
int dc[5] = {0,0,0,1,-1}; //위,아래,오른쪽,왼쪽
shark sh[10001];
map<int,int> dirmap = {{1,2},{2,1},{3,4},{4,3}};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    long long ans = 0;
    int R_size,C_size,M;
    cin >> R_size >> C_size >> M;
    for(int i = 1; i<= M; i++){
        cin >> sh[i].r >> sh[i].c >> sh[i].speed >> sh[i].dir >> sh[i].size;
        sh[i].live = true;
        mp[sh[i].r][sh[i].c] = i;
    }

    for(int peo = 1; peo <= C_size; ++peo){
        for(int r = 1; r <= R_size; ++r ){//물고기 잡기
            int idx = mp[r][peo];
            if(idx!=0){
                ans += sh[idx].size;
                sh[idx].live = false;
                break;
            }
        }
        memset(mp,0,sizeof(mp));
        for(int i = 1; i<=M;i++){//물고기 정보 업데이트
            if(sh[i].live == false) continue;
            int nr = sh[i].r, nc = sh[i].c;
            int dir = sh[i].dir;
            int speed = sh[i].speed;
            if(dir <= 2) speed = speed%(2*(R_size-1));
            else{speed = speed%(2*(C_size-1));}
            for(int k = 0; k< speed;k++){//물고기 새 위치와 방향 구하기
                nr += dr[dir];
                nc += dc[dir];
                if(nr>R_size||nr<1||nc>C_size||nc<1){
                    dir = dirmap[dir];
                    nr += dr[dir]*2;
                    nc += dc[dir]*2;
                }
            }
            if(mp[nr][nc] != 0){
                int idx = mp[nr][nc];
                if(sh[idx].size > sh[i].size){
                    sh[i].live = false;
                }else{
                    sh[idx].live = false;
                    mp[nr][nc] = i;
                    sh[i].c = nc;
                    sh[i].r = nr;
                    sh[i].dir = dir;
                }
            }else{
                mp[nr][nc] = i;
                sh[i].c = nc;
                sh[i].r = nr;
                sh[i].dir = dir;
            }
        }
    }
    cout << ans;
    return 0;
}