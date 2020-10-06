#include <iostream>
using namespace std;
int arr[301][301];
int ssum[301][301];
int res1[10001][2];
int res2[10001][2];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int x,y;
	cin >> y;
	cin >> x;
	for (int i = 1; i <= y; i++) {
		for (int j = 1; j <= x; j++) {
			cin >> arr[i][j];
		}
	}

	int sey;
	cin >> sey;

	for (int i = 0; i < sey; i++) {
		cin >> res1[i][0];
		cin >> res1[i][1];
		cin >> res2[i][0];
		cin >> res2[i][1];

	}

	ssum[1][1] = arr[1][1];
	for (int i = 1; i <= x; i++) {
		ssum[1][i] = ssum[1][i-1] + arr[1][i];
	}
	for (int i = 2; i <= y; i++) {
		for (int j = 1; j <= x; j++) {
			int tmp = ssum[i-1][j];
			for (int k = 1; k <= j; k++) {
				tmp += arr[i][k];
			}
			ssum[i][j] = tmp;
		}
	}

	
	for (int i = 0; i < sey; i++) {
		int x = res1[i][1];
		int y = res1[i][0];
		int x1 = res2[i][1];
		int y1 = res2[i][0];

		int tmp = ssum[y1][x1];
		if (y > 1) tmp -= ssum[y - 1][x1];
		if (x > 1) tmp -= ssum[y1][x - 1];
		if (x > 1 && y > 1)tmp += ssum[y - 1][x - 1];
		cout << tmp << "\n";
	}
	
	return 0;

}