/*
알고스팟 - =출전 순서 정하기
solved by SY
multiset을 사용해 본것에 의의
거기다 lower_bound를 오랜만에 사용
lower_bound : key의 가장 작은 "이상"값 리턴
upper_bound : key의 가장 작은 "초과"값 리턴
탐욕법
DATE : 2020.10.06
*/
#include <iostream>
#include <set>
using namespace std;

int solve(int n) {
	int a[101] = { 0, };
	int win = 0;
	multiset<int> b;
	for (int i = 0; i < n; ++i) cin >> a[i];
	
	for (int i = 0; i < n; ++i) {
		int tmp = 0;
		cin >> tmp;
		b.insert(tmp);
	}
	for (int run = 0; run < n; ++run) {
		if (*b.rbegin() < a[run]) { b.erase(b.begin()); }
		else { b.erase(b.lower_bound(a[run])); ++win; }
	}
	return win;
}
int main() {
	int TC;
	int n;
	cin >> TC;
	while (TC--) {
		cin >> n;
		cout << solve(n) << "\n";
	}
	return 0;
}