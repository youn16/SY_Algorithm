#include <iostream>
#include <algorithm>
using namespace std;
long arr[100001];
long input[100001];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n=0,m=0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + n);
	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> input[i];
	}

	for(int i =0;i<m;i++){
		long long l, r, mid;
		l = 0; r = n - 1;
		while (true) {
			if (l > r) { cout << "0" << "\n"; break; }
			mid = (l + r + 1) / 2;
			if (arr[mid] == input[i]) { cout << "1" << "\n"; break; }
			else if (arr[mid] > input[i]) { r = mid - 1; }
			else if (arr[mid] < input[i]) { l = mid + 1; }
		}
	}

	return 0;
}