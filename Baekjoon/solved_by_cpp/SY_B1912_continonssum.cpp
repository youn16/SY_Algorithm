#include <iostream>
#include <algorithm>
using namespace  std;
int input[100001];
int res[1000001];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> input[i];
	}
	for (int i = 1; i <= n; i++) {
		res[i] = max(res[i - 1] + input[i],input[i]);
	}

	cout << *max_element(res+1,res+n+1)<< "\n";

	return 0;
}