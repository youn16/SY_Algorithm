#include <iostream>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;
long long r[100001];
long long rec(int n) {
	vector<pair<int, long long> > v;
	long long res = 0;
	long long tmp = 0;
	for (int i = 0; i < n; i++) {
		while (true) {
			if (v.empty() || v.back().second <= r[i]) break;
			long long y = v.back().second;
			v.pop_back();
			int width = i;
			if (!v.empty()) {
				width = (i - v.back().first - 1);
			}
			tmp = width * y;
			if (tmp > res)res = tmp;
		}
		v.push_back(make_pair(i, r[i]));
	}

	int last = v.back().first+1;
	while (!v.empty()) {
		long long y = v.back().second;
		v.pop_back();
		int width = last;
		if (!v.empty()) {
			width = (width - v.back().first-1);
		}
		tmp = width * y;
		if (tmp > res)res = tmp;
	}
	return res;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	while (true) {
		int n;
		cin >> n;
		if (n == 0) {
			break;
		}
		memset(r, 0, sizeof(int) * 100001);
		for (int i = 0; i < n; i++) {
			cin >> r[i];
		}
		cout << rec(n) << endl;

	}
	return 0;
}