/*
백준 - B1003번 : 피보나치 함수
solved by SY
DATE : 2020.07.20
*/
#include <iostream>
using namespace std;
int zero[41];
int one[41];
void fibonacci(int n) {
	for (int i = 1; i < n; i++) {
		zero[i] = one[i - 1];
		one[i] = one[i - 1] + zero[i - 1];
	}
}

int main() {
	int n;
	cin >> n;
	zero[0] = 1;
	one[0] = 0;
	fibonacci(41);
	for (int i = 0; i < n; i++) {
		int k;
		cin >> k;
		cout << zero[k] << " " << one[k] << "\n";
	}
	return 0;
}
