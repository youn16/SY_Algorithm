#include <iostream>
#include <queue>
#include <stack>
using namespace std;
int check[100001];
int from[100001];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, k;

	cin >> n >> k;
	
	if (n == k) { cout << 0 << "\n"; cout << n << " "; return 0; }

	queue<int> q;
	q.push(n);
	check[n] = 0;

	while (!q.empty() || (check[k]== 0)) {
		int x = q.front();q.pop();
		if ((x - 1) >= 0 && check[x - 1] == false) {
			q.push(x - 1); check[x - 1] = check[x] + 1; from[x - 1] = x;
		}
		if ((x + 1) <= 100001 &&(x + 1) >= 0 && check[x + 1] == false) {
			q.push(x + 1); check[x + 1] = check[x] + 1; from[x + 1] = x;
		}
		if ((x * 2) <= 100001 && (x * 2) >= 0 && check[x * 2] == false) {
			q.push(x * 2); check[x * 2] = check[x] + 1; from[x * 2] = x;
		}
	}
	cout << check[k] << "\n";
	stack<int> s;
	s.push(k);
	int y = from[k];
	for (int i = check[k]; i > 0;i--) {
		s.push(y);
		y = from[s.top()];
	}

	for (int i = check[k]; i >= 0; i--) {
		cout << s.top() << " ";
		s.pop();
	}
	return 0;
}