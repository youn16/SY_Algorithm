#include <iostream>
#include <cstdio>
using namespace std;
int type[1001],memo[1001];
int main() {
	char input[1001];
	int n;

	cin >> n;
	cin >> input;

	for (int i = 0; i < n; i++) {
		if (input[i] == 'B') { type[i] = 0; }
		else if (input[i] == 'O') { type[i] = 1; }
		else if (input[i] == 'J') { type[i] = 2; }
	}
	for (int i = 1; i < n; i++) {
		int tmp=100000007;
		int flag = -1;
		for (int j = 0; j < i; j++) {
			if (type[i]!=0 && (type[j] + 1 == type[i])) {
				if ((memo[j] != -1) && (tmp > (i - j) * (i - j) + memo[j])) {
					tmp = (i - j) * (i - j) + memo[j];
					flag = 1;
					//printf("type %d = %d, type %d = %d\n",i, type[i],j, type[j]);
				}
			}
			if(type[i]==0 && type[j]==2) {
				if ((memo[j] != -1) && (tmp > (i - j) * (i - j) + memo[j])) {
					tmp = (i - j) * (i - j) + memo[j];
					flag = 1;
					//printf("typei = %d, typej = %d\n", type[i], type[j]);
				}
			}
		}
		if (flag == 1) {
			memo[i] = tmp;
		}
		else { memo[i] = -1; }
	} 

	cout << memo[n-1];
}