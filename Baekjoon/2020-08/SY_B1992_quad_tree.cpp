#include <iostream>
#include <cstdio>

using namespace std;
int map[64][64];
void quad(int x,int y,int n) {
	int first = map[y][x];
	if (n == 1) {
		if (first == 0)cout << 0;
		else cout << 1;
		return;
	}
	bool flag = true;
	for (int i = y; i < y+n; i++) {
		for (int j = x; j < x+n; j++) {
			if (map[i][j] != first) { flag = false; break; }
		}
		if (flag == false) { break; }
	}
	if (flag) {
		if (first == 0)cout << 0;
		else cout << 1;
	}
	else if (flag == false) {
		cout << "(";
		quad(x, y, n / 2);
		quad(x+n/2, y, n / 2);
		quad(x, y+n/2, n / 2);
		quad(x+n/2, y+n/2, n / 2);
		cout << ")";
	}
}
int main() {
	int  n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%1d",&map[i][j]);
		}
	}

	quad(0, 0, n);

	return 0;
}