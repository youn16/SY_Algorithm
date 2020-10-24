#include <iostream>
#include <algorithm>
using namespace std;

int n, k;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> k;
	int l = 1, r = k;
	int res = 0;
	while (l <= r) {
		int mid = (l + r) / 2;
		int sum = 0;
		if (l == r) { res = mid; break; }
		for (int i = 1; i <= n; i++) {
			sum += min(n, mid / i);
		}
		if (sum >= k) { r = mid; res = mid; }
		else { l = mid + 1; }
	}
	cout << res;
	return 0;
}
