/*
백준 - B19237 : 어른 상어
solved by SY
시뮬
DATE : 2020.10.16
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int map[21][21][2];//0 : 상어번호, 1 : 냄시
vector<vector<int>> shark;//상어번호, r, c, 바라보는 방향
int dir_prior[401][5][5];
int dr[5] = {0,-1,1,0,0};
int dc[5] = {0,0,0,-1,1};
int N,M,K;
bool cmp(vector<int> a,vector<int> b){if(a[0]<b[0]) return true; return false;}
int solve(){
    int res = 0;
    while(true){
        int size =shark.size(); 
        if(size==1) return res;
        if(res>999) return -1;
        ++res;
        for(int i = 0; i<size;i++){ //움직일곳 찾기
            int num  = shark[i][0], r = shark[i][1], c=shark[i][2], dir =shark[i][3];
            int nr = -1, nc = -1;
            int m = -1;
            for(int g=1;g<=4;g++){//냄시 없는 곳 중에 찾기
                m = dir_prior[num][dir][g];
                nr = r + dr[m]; nc = c + dc[m];
                if(nr<1||nr>N||nc<1||nc>N) {nr = -1; continue;}
                if(map[nr][nc][0]==0){break;}
                nr = -1; nc = -1;
            }
            if(nr == -1){
                for(int g=1;g<=4;g++){//냄시 나는 곳 중에 찾기
                m = dir_prior[num][dir][g];
                nr = r + dr[m]; nc = c + dc[m];
                if(nr<1||nr>N||nc<1||nc>N) continue;
                if(map[nr][nc][0]==num){break;}
                nr = -1; nc = -1;
                }
            }
            shark[i][1] = nr; shark[i][2] = nc; shark[i][3] = m;
        }
        for(int r = 1;r<=N;r++){// 냄시 없애기
            for(int c = 1; c<=N;c++){
                if(map[r][c][0] != 0){
                    if((--map[r][c][1]) == 0) map[r][c][0] = 0;
                }
            }
        }

        for(std::vector<vector<int>>::iterator iter = shark.begin(); iter != shark.end(); ){
            int num  = (*iter)[0], r = (*iter)[1], c=(*iter)[2], dir =(*iter)[3];
            if(map[r][c][0]!=0&&map[r][c][0]<num)
            {
                iter = shark.erase(iter);
            }
            else{
                map[r][c][0] = num;
                map[r][c][1] = K;
                ++iter;
            }
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin >> N >> M >> K;
    for(int r = 1;r<=N;r++){
        for(int c = 1; c<=N;c++){
            int input;
            cin >> input;
            if(input!=0){
                map[r][c][0] = input;
                map[r][c][1] = K;
                shark.push_back({input, r,c});
            }
        }
    }
    sort(shark.begin(),shark.end(),cmp);
    for(int i = 0; i<M;i++){
        int input;
        cin >> input;
        shark[i].push_back(input);
    }
    for(int i = 1; i<=M;i++){
        for(int j = 1; j<=4;j++){
            for(int k = 1;k<=4;k++){
            cin >> dir_prior[i][j][k];
            }
        }
    }
    cout << solve();    
    return 0;
}