#include <iostream>
using namespace std;

int tile[1001];

int tiling(int n) {
	tile[1] = 1;
	tile[2] = 2;
	for (int i = 3; i <= n; i++) {
		tile[i] = (tile[i - 1] + tile[i - 2])%10007;
	}
	return tile[n];
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	tiling(n);
	int res = tile[n] % 10007;

	cout << res;
	return 0;
}
