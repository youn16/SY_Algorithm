#include <iostream>
using namespace std;
long long arr[1000001];
long long n, m;
bool check(int mid) {
	long long sum = 0;
	for (int i = 0; i < n; i++) {
		if (arr[i] - mid > 0) { sum += (arr[i] - mid); }
	}
	if (sum >= m) return true;
	else return false;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> m;
	long long max = -1;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		if (arr[i] > max) { max = arr[i]; }
	}

	long long l, r;
	long long mid;

	l = 0; r = max;
	int res = 0;
	while (l < r) {
		mid = (l + r + 1) / 2;
		if (check(mid)) { l = mid; res = mid; }
		else { r = mid - 1; }	
	}

	cout << res;
	return 0;
}