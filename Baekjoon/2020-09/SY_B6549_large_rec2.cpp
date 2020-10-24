#include <iostream>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;
long long r[100001];
int rp[400004];	// 위치값 저장하는 배열
int init(long long *r, int start, int end, int node) {
	if (start == end) return rp[node] = start;
	int mid = (start + end) / 2;
	int l_min = init(r, start, mid, node * 2);
	int r_min = init(r, mid+1, end, node * 2 + 1);
	if (r[l_min] < r[r_min]) return (rp[node] = l_min);
	return rp[node] = r_min;
}
int q(int n_left,int n_right, int left, int right,int node) {
	if (n_left > right || n_right < left) return -10;
	if (left <= n_left && n_right <= right) {
		return rp[node];
	}
	int mid = (n_left + n_right) / 2;
	int l_min = q(n_left,mid, left, right, node * 2);
	int r_min = q(mid + 1,n_right, left, right, node * 2 + 1);
	if (l_min < 0) return r_min;
	else if (r_min < 0) return l_min;

	if (r[l_min] < r[r_min]) return l_min;
	return r_min;
}
long long rec(int left,int right,int n) {
	long long now;
	long long l_area;
	long long r_area;

	if (left == right) return r[left] * 1;
	if (right > n || left < 0) return -1;
	if (right < left) return -1;
	int x = q(0, n - 1, left, right, 1);
	int width = right-left+1;
	now = r[x] * width;
	l_area = rec(left,x-1, n);
	r_area = rec(x+1, right, n);
	return max({now,l_area,r_area});
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
		memset(rp, 0, sizeof(int) * 400004);
		for (int i = 0; i < n; i++) {
			cin >> r[i];
		}
		init(r, 0, n - 1, 1);
		cout << rec(0,n-1,n)<< endl;

	}
	return 0;
}