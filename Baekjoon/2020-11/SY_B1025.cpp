#include <iostream>
#include <math.h>
#define max(a,b) a>b?a:b
using namespace std;

int N,M;
char input[10][10];
bool issqul(int a){
    unsigned int tmp = (unsigned int)(sqrt((double)a))+0.5;
    return tmp*tmp == a;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin >> N >> M;
    int res = -1;
    for(int i = 0; i < N; i++){
        cin >> input[i];
    }
    for(int y = 0; y < N; y++){
        for(int x = 0; x < M; x++){
            for(int diff_y = -N; diff_y < N; diff_y++){
                for(int diff_x = -M; diff_x < M; diff_x++){
                    if(diff_x == 0 && diff_y ==0) continue;
                    int tmp = 0;
                    int curX = x;
                    int curY = y;
                    while(curX>=0 && curX<M && curY>=0 && curY<N){
                        tmp = tmp*10 + input[curY][curX] - '0';
                        if(issqul(tmp)) res = max(res,tmp);
                        curY += diff_y;
                        curX += diff_x;
                    }
                }    
            }
        }
    }
    cout << res;
    return 0;
}