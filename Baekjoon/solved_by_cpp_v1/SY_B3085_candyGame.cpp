/*
백준 - B3085번 : 사탕 게임
solved by SY
브루트포스 + 시뮬레이션 문제
DATE : 2020.10.04
*/
#include <iostream>
using namespace std;
char box[51][51];
int mr[2] = { 0,1 };
int mc[2] = { 1,0 };
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n = 0;

	cin >> n;

	for (int r = 0; r < n; r++) {
		for (int c = 0; c < n; c++) {
			cin >> box[r][c];
		}
	}
	int max = -1;
	for (int r = 0; r < n; r++) {
		for (int c = 0; c < n; c++) {
			for (int i = 0; i < 2; i++) { //0 : 가로 -> 세로를 비교할 것, 1 : 세로 -> 가로를 비교할 것
				int nr = r + mr[i];
				int nc = c + mc[i];
				if (nr < 0 || nr >= n || nc < 0 || nc >= n) continue;
				char a = box[r][c], b = box[nr][nc];
				if (a != b) {
					box[r][c] = b;
					box[nr][nc] = a;
					int idx = 1;
					for (int y = 0; y < n; ++y) {
						idx = 1; char t = box[y][0];
						for (int x = 1; x < n; ++x) {
							if (t == box[y][x]) ++idx;
							else { 
								if (max < idx) max = idx;
								t = box[y][x];
								idx = 1; 
							}
						}
						if (max < idx) max = idx;
					}
					for (int x = 0; x < n; ++x) {
						idx = 1; char t = box[0][x];
						for (int y = 1; y < n; ++y) {
							if (t == box[y][x]) ++idx;
							else {
								if (max < idx) max = idx;
								t = box[y][x];
								idx = 1;
							}
						}
						if (max < idx) max = idx;
					}
					box[r][c] = a;
					box[nr][nc] = b;
				}
			}
		}
	}
	cout << max;

	return 0;
}
