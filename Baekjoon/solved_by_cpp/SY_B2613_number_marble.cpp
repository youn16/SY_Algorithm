#include <iostream>
using namespace std;
int arr[301];
int n, m;
int bb[101];
bool check(int mid) {
	int cnt = 1;
	int sum = 0;
	for (int i = 0; i < n; i++) {
		sum += arr[i];
		if (sum > mid) { cnt++; sum = arr[i]; }
		if (cnt > m) return false;
	}
	return true;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;
	int max = -1;
	int sum = 0;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		sum += arr[i];
		if (arr[i] > max) max = arr[i];
	}

	int l, r, mid = 0;
	
	l = max; r = sum;
	int res = 0;

	while (l < r) {
		mid = (l + r) / 2;
		bool c = check(mid);

		if (c) { r = mid; res = mid; }
		else { l = mid+1; }
	}
	cout << res << "\n";

	int cnt = 1;
	int num = 0;
	int sum1 = 0;
	for (int i = 0; i < n; i++) {
		sum1 += arr[i];
		if (sum1 > res) { 
			cnt++;
			sum1 = arr[i];
			cout << num << " ";
			num = 0;
		}
		num++;

		if ((m - cnt) == (n - (i + 1))) { cout << num << " "; break; }
	}
	for (int i = 0; i < (m - cnt); i++) {
		cout << 1 << " ";
	}
	
	return 0;
}