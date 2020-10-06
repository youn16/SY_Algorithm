#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool cmp(pair<int,int> a, pair<int, int> b) {
	if (a.first < b.first) return true;
	else if (a.first == b.first) {
		if (a.second <= b.second) return true;
	}
	return false;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	vector<pair<int, int> > v;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		pair<int, int> a;
		cin >> a.first >> a.second;
		v.push_back(a);
	}
	sort(v.begin(), v.end(), cmp);
	for (int i = 0; i < n; i++) {
		cout << v[i].first<<" "<< v[i].second << '\n';
	}
	return 0;
}