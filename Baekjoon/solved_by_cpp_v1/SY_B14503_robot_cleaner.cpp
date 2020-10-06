#include <iostream>
using namespace std;
int wall[51][51];
bool visit[51][51];
int move_y[] = { -1,0,1,0 };
int move_x[] = { 0,1,0,-1 };
int cnt = 0;
void dfs(int r, int c, int d) {
	if (wall[r][c] == 0 && visit[r][c] == false) { visit[r][c] = true; cnt++; }
	bool flg = false;
	for (int i = 1; i <= 4; i++) {
		int dd = (d + 4 - i) % 4;
		int yy = r + move_y[dd];
		int xx = c + move_x[dd];
		//if (yy < 0 || yy>n || xx < 0 || xx>m) { continue; }
		if (visit[yy][xx] == 0 && wall[yy][xx] == 0) {
			flg = true;
			dfs(yy, xx, dd);
			break;
		}
	}
	if (!flg) {
		int dd = (d + 2) % 4;
		int yy = r + move_y[dd];
		int xx = c + move_x[dd];
		//if (yy < 0 || yy>n || xx < 0 || xx>m) { return; }
		if (wall[yy][xx] == 0) { dfs(yy, xx, d); }
		else { return; }
	}
	return;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int r, c, d;
	int n, m;
	cin >> n >> m;
	cin >> r >> c >> d;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> wall[i][j];
		}
	}
	dfs(r, c, d);
	cout << cnt;
	return 0;
}