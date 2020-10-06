#include <iostream>
using namespace std;
int arr[10001][10001];
int map[10001][10001];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int max = 0;

			if (i > 0 && j > 0) {
				if (map[i - 1][j - 1] > max) { max = map[i - 1][j - 1]; }
			}
			if (i > 0) { 
				if (map[i - 1][j] > max) { max = map[i - 1][j]; } 
			}
			if (j > 0) {
				if (map[i][j - 1] > max) { max = map[i][j - 1]; }
			}
			map[i][j] = max + arr[i][j];
		}
	}
	cout << map[n - 1][m - 1];
	return 0;
}