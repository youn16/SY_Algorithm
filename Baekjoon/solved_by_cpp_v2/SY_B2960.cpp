#include <iostream>
using namespace std;
int map[1001];
int main(){
    int N,K;
    cin >> N >>K;
    int cnt =0;
    for(int i =2;i<=N;i++){
        if(map[i]!=0) continue;
        map[i]=1;
        ++cnt;
        if(cnt==K)cout << i;
        for(int j = 2;j*i<=N;j++){
            if(map[i*j]==0){
                map[i*j]=1;
                ++cnt;
                if(cnt==K)cout << i*j;
            }
        }
    }
    return 0;
}
