#include<iostream>
#include<vector>
#define abs(a) a<0?-a:a
#define min(a,b) a<b?a:b
#define ll long long
using namespace std;
vector<ll> v;
int n;
ll check(ll mid) {//mid : 간격, mm : 이동거리
	ll res = 0;
	for (int i = 0; i < n; i++) {
		int tmp = v[i] - (i * mid);
		res += abs(tmp);
	}
	return res;
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		ll tmp = 0;
		cin >> tmp;
		v.push_back(tmp);
	}
	ll left = 1;
	ll right = 1e9;
	while (left+3 <= right) {
		ll l = (left*2 + right) / 3;
		ll r = (left + right * 2) / 3;
		ll cl = check(l);
		ll cr = check(r);
		if (cl > cr) {
			left = l;
		}
		else {
			right = r;
		}
	}
	ll mm = 1e18;
	for (int i = left; i <= right; i++) {
		mm = min(mm, check(i));
	}

	cout << mm;
	return 0;
}