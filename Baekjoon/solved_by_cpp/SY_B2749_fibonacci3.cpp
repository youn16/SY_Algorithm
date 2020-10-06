#include <iostream>

using namespace std;
int main(){
	long long n;
	cin >> n;
	int p = 15 * 1000000 / 10;
	long* dp = new long[p + 50];
	int ans = n % p;
	//�ǻ�� �ֱⰡ p�϶� N��° �Ǻ���ġ���� K�� ���� ��������
	//N%P��° �Ǻ���ġ ���� K�� ���� �������� ����
	//K�� 10^k�� �� �ǻ�� �ֱ� ���ϴ� ���� = 15*K/10

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