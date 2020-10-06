#include <iostream>

using namespace std;
int main(){
	long long n;
	cin >> n;
	int p = 15 * 1000000 / 10;
	long* dp = new long[p + 50];
	int ans = n % p;
	//피사노 주기가 p일때 N번째 피보나치수를 K로 나눈 나머지는
	//N%P번째 피보나치 수를 K로 나눈 나머지와 같다
	//K가 10^k일 때 피사노 주기 구하는 공식 = 15*K/10

	dp[0] = 0; dp[1] = 1;
	if (ans < p) {
		for (int i = 2; i <= ans; i++) {
			dp[i] = (dp[i - 1] + dp[i - 2])%1000000;
		}
	}
	else {
		for (int i = 2; i <= p; i++) {
			dp[i] = (dp[i - 1] + dp[i - 2])%1000000;
		}
	}

	cout << dp[ans % p];
	
	return 0;

}