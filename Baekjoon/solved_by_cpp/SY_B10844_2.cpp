#include <iostream>

using namespace std;
long long res[101][10];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	for (int i = 1; i < 10; i++) {
		res[1][i] = 1;
	}

	for (int i = 2; i < n+1; i++) {
		for (int j = 1; j < 9; j++) {
			res[i][j] = (res[i-1][j - 1] + res[i-1][j + 1])%1000000000;
		}

		res[i][0] = res[i - 1][1] % 1000000000;
		res[i][9] = res[i-1][8]%1000000000;
	}
	long long a = 0;
	for (int i = 0; i < 10; i++) {
		a += res[n][i];
	}

	cout << a%1000000000;

	return 0;
}