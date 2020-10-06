#include <iostream>

using namespace std;
long long res;
int g[5];
int one, eight;
void stairs(int n, int pos, int val) {
	if (pos == n) {
		if (1 == val) one++;
		if (8 == val) eight++;
		/*g[pos] = val; cout << g[1] << g[2] << g[3] << "\n";*/ 
		res++; return;
	}
	if (pos > n)return;
	//if (pos % 10 == 0) { res = res % 1000000000; }
	if(val-1>=0 && (val - 1) < 10) {
		/*g[pos] = val;*/
		stairs(n, pos + 1, val - 1);
	}
	 if(val + 1 >= 0 && (val + 1) < 10){
		stairs(n, pos+1, val + 1);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	for (int i = 1; i < 10; i++) {
		stairs(n, 1, i);
	}

	cout << res << " 1 : " <<one<<" 8 : "<<eight<<"\n" ;

	return 0;
}