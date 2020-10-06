#include<iostream>
#include<algorithm>
#include<functional>
using namespace std;
long long input[10001];
int n, k;

bool desc(int a, int b) {
	return a > b;
}

bool check(long long t) {
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		cnt += (input[i] / t);
	}
	if (cnt >= k)return true;
	return false;
}

int parametric_iter(long long MIN, long long MAX) {
	long long ret = 1;
	long long l = MIN, r = MAX;
	while (l < r) {
		long long mid = (l + r + 1) / 2;
		long long c = check(mid);

		if (c) {
			l = mid;
			ret = mid;
		}
		else {
			r = mid - 1;
		}
	}

	return ret;
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> input[i];
	}
	sort(input,input+n,desc);

	long long ret = parametric_iter(1, input[0]);
	cout << ret;

	return 0;
}