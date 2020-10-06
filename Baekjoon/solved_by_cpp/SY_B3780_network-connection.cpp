#include <iostream>
#include <string.h>
using namespace std;
int node[20001][2];
int find(int v) {
	if (node[v][0] == v) return v;
	int pv = find(node[v][0]);
	node[v][1] += node[node[v][0]][1];
	node[v][0] = pv;
	return pv;
}
void unio() {
	int i, j;
	cin >> i >> j;
	node[i][0] = j;
	int tmp = i - j;
	if (tmp < 0) tmp = tmp * (-1);
	node[i][1] = tmp % 1000;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int t = 0;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int n = 0;
		cin >> n;
		memset(node, 0, sizeof(int)*20001);
		for (int j = 1; j <= n; j++) {
			node[j][0] = j;
		}
		while (true) {
			char input = '0';
			cin >> input;
			if (input == '0') { break; }
			if (input == 'E') { int v; cin >> v; find(v); cout << node[v][1] << "\n"; }
			else if (input == 'I') { unio(); }
			else { break; }
		}
	}
	return 0;
}