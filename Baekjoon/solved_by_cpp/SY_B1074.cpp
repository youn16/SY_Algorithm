#include <iostream>
using namespace std;
int find_z(int n,int r,int c) {
	if (n == 1) {
		return 0;
	}
	int t = n / 2;
	if (r <= t && c <= t) {//1quadrant
		return find_z(n / 2, r, c);
	}
	else if (r <= t && c > t) {//2quadrant
		return find_z(n / 2, r, c - n / 2) + (n / 2) * (n / 2);
	}
	else if (r > t && c <= t) {//3quadrant
		return find_z(n / 2, r - n / 2, c) + (n / 2) * (n / 2)*2;
	}
	else if (r > t && c > t) {//4quadrant
		return find_z(n / 2, r - n / 2, c- n / 2) + (n / 2) * (n / 2) * 3;
	}
}
int fastsquare(int n) {
	int ans = 1;
	int a = 2;
	while (n != 0) {
		if (n % 2 == 1) {
			ans *= a;
		}
		a *= a;
		n /= 2;
	}
	return ans;
}
int main() {
	int n, r, c;
	cin >> n >> r >> c;
	int square = fastsquare(n);
	int res = find_z(square, r + 1, c + 1);

	cout << res;

	return 0;
}
