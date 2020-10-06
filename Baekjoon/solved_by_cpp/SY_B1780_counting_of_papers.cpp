#include<iostream>
#include<cstdio>
using namespace std;

int map[2188][2188];
int count_s[3]; // -1,0,1
int d_x[9] = { 0,0,0,1,1,1,2,2,2 };
int d_y[9] = { 0,1,2,0,1,2,0,1,2 };

void counting(int x, int y, int n) {
	int first = map[x][y];
	bool flag = false;

	//printf("x : %d y : %d n : %d\n",x,y,n);
	if (n == 1) {
		if (first == -1) { count_s[0] += 1; }
		if (first == 0) { count_s[1] += 1; }
		if (first == 1) { count_s[2] += 1; }
		return;
	}

	for (int i = x; i < x+n; i++) {
		for (int j = y; j < y+n; j++) {
			//cout << map[i][j] << " ";
			if (map[i][j] != first) {
				flag = true;
				//cout << "break" << endl;
				break;
			}
		}
		//cout << "\n";
		if (flag == true) break;
	}

	if (first == -1 && flag == false) { count_s[0] += 1; return; }
	if (first == 0 && flag == false) { count_s[1] += 1; return; }
	if (first == 1 && flag == false) { count_s[2] += 1; return; }

	counting(x, y, n / 3);
	counting(x, y + n / 3, n / 3);
	counting(x, y + n / 3 * 2, n / 3);
	counting(x + n / 3, y, n / 3);
	counting(x + n / 3, y + n / 3, n / 3);
	counting(x + n / 3, y + n / 3 * 2, n / 3);
	counting(x + n / 3 * 2, y, n / 3);
	counting(x + n / 3 * 2, y + n / 3, n / 3);
	counting(x + n / 3 * 2, y + n / 3 * 2, n / 3);

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
		}
	}

	counting(0, 0, n);

	for (int i = 0; i < 3; i++) {
		cout << count_s[i] << endl;
	}

	return 0;
}
