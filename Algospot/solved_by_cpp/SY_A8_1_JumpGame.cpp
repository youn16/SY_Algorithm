/*
알고스팟 - 외벽뛰기
solved by SY
동적 계획 문제, 메모리제이션을 사용
DATE : 2020.09.30
*/
#include <iostream>
#include <cstring>
int map[101][101];
int ch[101][101];
int n;
using namespace std;
int jump(int y, int x) {
	if (y>=n||x>=n)	return 0;
	if (y == n - 1 && x == n-1) return 1;
	int& ret = ch[y][x];
	if (ret != -1) return ret;
	int a = map[y][x];
	return ret = (jump(y + a, x) || jump(y, x + a));
}
int main(void) {
	int t;
	cin >> t;
	while (t--) {
		n = 0;
		cin >> n;
		memset(map, 0, sizeof(map));
		memset(ch, -1, sizeof(ch));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> map[i][j];
			}
		}
		if(jump(0, 0))cout << "YES" <<"\n";
		else { cout << "NO" << "\n"; }
	}
	return 0;
}
