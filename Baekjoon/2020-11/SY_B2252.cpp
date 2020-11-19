#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int N,M;
vector<int> V[32001];
int save[32001];
int res[32001];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin >> N >> M;
    for(int i = 0; i< M; i++){
        int from,to;
        cin >> from >> to;
        V[from].push_back(to);
        save[to] +=1;
    }
    queue<int> Q;
    for(int i = 1; i<=N; i++){
        if(save[i] == 0){
            Q.push(i);
        }
    }
    for(int i = 1; i<=N; i++){
        if(Q.empty()){
            cout << "error" <<"\n";// 사이클 발생
            return 0;
        }
        int now = Q.front();
        cout << now << " ";
        Q.pop();
        for(int idx = 0; idx < V[now].size(); idx++){
            int next = V[now][idx];
            save[next] -=1;
            if(save[next]==0){
                Q.push(next);
            }
        }
    }
    return 0;
}