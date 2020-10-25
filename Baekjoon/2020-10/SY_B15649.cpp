/*
백준 - B15649 : N과 M
solved by SY
백트래킹
DATE : 2020.10.26
*/
#include <iostream>
#include <vector>

using namespace std;

vector<int> v;
bool sel[9];
int N,M;
void mprint(){
    for(int i = 0; i< M; i++){
        cout << v[i]<<" ";
    }
    cout << "\n";
}

void DFS(int cnt){
    if(cnt == M){
        mprint();
        return; 
    }
    for(int i = 1; i<= N;i++){
        if(sel[i]==true) continue;
        sel[i] = true;
        v.push_back(i);
        DFS(cnt+1);
        sel[i]=false;
        v.pop_back();
        
    }
}

int main(){
    cin >> N >> M;
    DFS(0);
    return 0;
}