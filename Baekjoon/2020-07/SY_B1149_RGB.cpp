#include<iostream>
#include<algorithm>
using namespace std;
int input[1001][3];
int memo[1001][3];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> input[i][0];
		cin >> input[i][1];
		cin >> input[i][2];
	}
	memo[0][0] = input[0][0];
	memo[0][1] = input[0][1];
	memo[0][2] = input[0][2];
	for (int i = 1; i < n; i++) {
		memo[i][0] = min(memo[i - 1][1], memo[i - 1][2])+input[i][0];
		memo[i][1] = min(memo[i - 1][0], memo[i - 1][2]) + input[i][1];
		memo[i][2] = min(memo[i - 1][0], memo[i - 1][1]) + input[i][2];
	}
	cout << min({ memo[n - 1][0],memo[n - 1][1],memo[n - 1][2] });

	return 0;
}