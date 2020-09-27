/*
백준 1865번 웜홀 문제 by SY
벨만포드 알고리즘을 적용한 문제이다.
음수 사이클을 찾는 방법에 대한 고찰이 필요한 문제.
Date : 2020.09.26
*/
#include <iostream>
#include <vector>
#include <algorithm>
#define INF 1e9+7
using namespace std;
int tc;
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> tc;
	while (tc--) {
		int n, m, w;
		cin >> n >> m >> w;
		vector<vector<int>> edge;
		for (int i = 0; i < m; i++) {
			int s, e, t;
			cin >> s >> e >> t;
			edge.push_back({ s,e,t });
			edge.push_back({ e,s,t });
		}
		for (int i = 0; i < w; i++) {
			int s, e, t;
			cin >> s >> e >> t;
			edge.push_back({ s,e,-t });
		}
		int dist[501];
		bool flag = true;
		fill(dist, dist + 501, 1e9 + 7);
		dist[1] = 0;
		for (int i = 0; i < (m + w); i++) {
			for (int j = 0; j < edge.size(); j++) {
				int s = edge[j][0];
				int e = edge[j][1];
				int v = edge[j][2];
				dist[e] = min(dist[e], dist[s] + v);
			}
		}
		for (int j = 0; j < edge.size(); j++) {
			int s = edge[j][0];
			int e = edge[j][1];
			int v = edge[j][2];
			if (dist[s] == INF) continue;
			if (dist[s] + v < dist[e]) {
				cout << "YES" << "\n";
				flag = false; break;
			}
		}
		if (flag) { cout << "NO" << "\n"; }
	}

	return 0;
}
