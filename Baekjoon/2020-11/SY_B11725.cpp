#include <iostream>
#include <vector>
using namespace std;
vector<int> tree[100001];
bool check[100001];
int parentNode[100001];
void dfs(int node){
    check[node]=true;
    for(int i = 0; i< tree[node].size();i++){
        int next = tree[node][i];
        if(check[next]==false){
            parentNode[next] = node;
            dfs(next);
        }
    }
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int N = 0;
    cin >> N;    
    for(int i =0; i<N-1;i++){
        int from = 0, to = 0;
        cin >> from >> to;
        tree[from].push_back(to);
        tree[to].push_back(from);
    }
    dfs(1);
    for(int i = 2; i <= N; i++){
        cout << parentNode[i] << "\n";
    }
    return 0;
}