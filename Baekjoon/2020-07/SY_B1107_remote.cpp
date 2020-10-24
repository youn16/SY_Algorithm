#include <iostream>
using namespace std;
int brokenbts[11];
int main() {
	int N,M;
	cin >> N >> M;

	for (int i = 0; i < M; i++) {
		cin >> brokenbts[i];
	}

	int res,tmp;
	tmp = 0;
	res = abs(N-100);
	for (int i = 0; i < 1000000; i++) {
		int t = i;
		int push = 0;
		bool flag = false; 
		if (i == 0) {
			for (int j = 0; j < M; j++) {
				if (brokenbts[j] == (t % 10)) {
					flag = true; break;
				}
			}
			if (flag == true) {
				push++;
			}
		}
		else {
			while (t > 0) {
				for (int j = 0; j < M; j++) {
					if (brokenbts[j] == (t % 10)) {
						flag = true; break;
					}
				}
				if (flag == true) {
					break;
				}
				t /= 10;
				push++;
			}
		}
		if (flag == true) continue;
		tmp = abs(N - i);
		if (tmp + push < res) { res = tmp + push; }
	}
	cout << res;
	return 0;
}