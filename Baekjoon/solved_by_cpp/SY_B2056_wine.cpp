#include <iostream>
#include <algorithm>

using namespace std;
int wine[10001];
int maxwine[10001];

void drink(int i) {
	maxwine[1] = wine[1];
	maxwine[2] = wine[1] + wine[2];
	for (int n = 3; n <= i;n++) {
		int tmp;
		tmp = maxwine[n - 1];
		if (tmp < maxwine[n - 2] + wine[n]) {
			tmp = maxwine[n - 2] + wine[n];
		}
		if (tmp < maxwine[n - 3] + wine[n - 1] + wine[n]) {
			tmp = maxwine[n - 3] + wine[n - 1] + wine[n];
		}
		maxwine[n] = tmp;
		//cout << n <<" "<< maxwine[n]<<"\n";
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;	
	for (int i = 1; i <= n; i++) {
		cin >> wine[i];
	}

	drink(n);
	cout << maxwine[n];
	return 0;
}