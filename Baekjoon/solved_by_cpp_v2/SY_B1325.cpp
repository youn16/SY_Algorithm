/*
백준 - B1325 : 효율적인 해킹
solved by SY
깊이 우선 탐색, 그래프
DATE : 2020.10.08
*/
#include <iostream>
#include <vector>
#include <cstring>
#define max(a,b) a>b?a:b
using namespace std;
bool visited[10001];
int tmp = 0;
void dfs(vector<int> v[],int i){
    visited[i] = true;
    ++tmp;
    for(int k = 0; k<v[i].size();k++){
        int next = v[i][k];
        if(!visited[next]){
            dfs(v,next);
        }
    } 
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> v[n+1];
    int idx[10001] = {1,};

    for(int i = 0;i<m;i++){
        int from, to;
        cin >> to >> from;
        v[from].push_back(to);
    }
    int mx = 1;
    for(int i = 1; i<=n;i++){
        if(v[i].empty()) continue;
        memset(visited,false,sizeof(visited));
        tmp = 0;
        dfs(v,i);
        idx[i] = tmp;
        mx = max(mx,tmp);
    }
    for(int i = 1; i<=n;i++){
        if(idx[i]==mx) cout << i <<" ";
    }
    return 0;
}