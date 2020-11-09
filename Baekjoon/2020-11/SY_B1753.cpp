#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define INF 1e9+7
using namespace std;
int V,E,S;
vector<pair<int,int>> input[20001];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int dist[20001];
    fill(dist, dist+20001, INF);
    cin >> V >> E;
    cin >> S;
    for(int i = 0; i<E; i++){
        int from,to,val;
        cin >> from >> to >> val;
        input[from].push_back(make_pair(to,val));
    }
    priority_queue<pair<int,int>> qu;//cost,next
    dist[S]=0;
    qu.push(make_pair(0,S));
    while(!qu.empty()){
        int cost = -qu.top().first;
        int here = qu.top().second;
        qu.pop();
        for(int i = 0; i<input[here].size();i++){
            int to = input[here][i].first;
            int val = input[here][i].second;
            if(dist[to]>dist[here]+val){
                dist[to] = dist[here]+val;
                qu.push(make_pair(-dist[to],to));
            }
        }
    }
    for(int i = 1; i<=V; i++){
        if(dist[i]==INF){cout << "INF" << "\n";}
        else{cout << dist[i] << "\n";} 
    }
    return 0;
}