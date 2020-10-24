#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<pair<long long, long long> > v;
int main() {
	ios::sync_with_stdio(false);
	int n;
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		long long x, y;
		cin >> x >> y;
		v.push_back(make_pair(y, x));
	}

	sort(v.begin(), v.end());
	int cnt = 1;
	int i = 1;
	long long now_end = v[0].first;
	while(true) {
		long long next_start, next_end;
		next_start = v[i].second;
		next_end = v[i].first;
		if (next_start >= now_end) {
			now_end = next_end;
			cnt++;
		}
		i++;

		if (i >= n) break;
	}
	cout << cnt;

	return 0;
}