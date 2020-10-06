#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
long map[101];
int gcd(int a, int b) {
	if (a < b)swap(a, b);
	if (b == 0)return a;
	return gcd(b, a % b);
}
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> map[i];
	}
	sort(map, map + n);

	int min = map[1] - map[0];
	for (int i = 2; i < n; i++) {
		min = gcd(min,map[i]-map[i-1]);
	}
	vector<int> r;
	for (int i = 2; i*i <= min; i++) {
		if (min%i==0) {
			r.push_back(i);
			bool flag = true;
			for (int j = 0; j < r.size(); j++) {
				if (min / i == r[j]) { flag = false; break; }
			}
			if(flag)r.push_back(min/i);
		}
	}
	bool flag = true;
	for (int j = 0; j < r.size(); j++) {
		if (min == r[j]) { flag = false; break; }
	}
	if (flag)r.push_back(min);
	sort(r.begin(), r.end());
	for (int i = 0; i < r.size(); i++) {
		cout << r[i] << " ";
	}
	return 0;
}