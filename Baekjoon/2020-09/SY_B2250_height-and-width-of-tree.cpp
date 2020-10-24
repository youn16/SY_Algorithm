#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
bool check[10000];
bool chch[10000];
int ch[10000];
vector<vector<int>> v;
int cnt;
bool cmp(vector<int> a,vector<int> b) {
	if (a[0] < b[0])return true;
	return false;
}
bool cmp_2(vector<int> a, vector<int> b) {
	if (a[4] < b[4])return true;
	else if (a[4] == b[4]) {
		if (a[3] < b[3]) return true;
	}
	return false;
}
void dfs(int n) {
	chch[n] = true;
	int left = v[n][1];
	int right = v[n][2];
	if (left == -1 && right == -1) { v[n].push_back(++cnt); return; }
	if (left != -1) {
		if (chch[left] == false) { 
			dfs(left); v[n].push_back(++cnt);}
	}
	if (right != -1) {
		if (chch[right] == false) {
			if (left == -1) { v[n].push_back(++cnt); dfs(right); }
			else
			{dfs(right);}
		}
	}
}
void bfs(int n) {
	queue<int> q;
	q.push(n);
	ch[n] = 1;
	v[n].push_back(ch[n]);
	while (!q.empty()) {
		int i = q.front(); q.pop();
		int left = v[i][1], right = v[i][2];
		if (left != -1) {
			if (ch[left] == 0) { 
				q.push(left);
				ch[left] = ch[i] + 1; 
				v[left].push_back(ch[left]);
			}
		}
		if (right != -1) {
			if (ch[right] == false) {
				q.push(right);
				ch[right] = ch[i] + 1;
				v[right].push_back(ch[right]);
			}
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n;
	v.push_back({0, 0, 0, 0, 0});//본인, 왼쪽, 오른쪽, x축 위치, level;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a, b, c;
		vector<int> g;
		cin >> a >> b >> c;
		g.push_back(a); g.push_back(b); g.push_back(c);
		v.push_back(g);
	}
	sort(v.begin(), v.end(),cmp);
	for (int i = 1; i <= n; i++) {
		if (v[i][1] != -1) { check[v[i][1]] = true; }
		if (v[i][2] != -1) { check[v[i][2]] = true; }
	}
	int root = 0;
	for (int i = 1; i <= n; i++) {
		if (check[i] == false) { root = i; break; }
	}
	dfs(root);
	bfs(root);
	sort(v.begin(), v.end(), cmp_2);
	int k; int tmp = 1, tl = 1;
	int from,to;
	for (int i = 2; i <= n;) {
		int level = v[i][4];
		from = v[i][3];
		k = v[i][4];
		while(k == level) {
			i++; 
			if (i > n) { break; }
			level = v[i][4];
		}
		to = v[i - 1][3];
		if (tmp < (to - from + 1)) { tmp = to - from + 1; tl = k; }
	}

	cout << tl << " " << tmp;
	return 0;
}