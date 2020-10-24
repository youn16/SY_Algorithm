#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;
int check[10000];
int from[10000];
char how[10000];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n,x,y;
	cin >> n;
	cout << sizeof(check);
	queue<int> q;
	while (n-- > 0) {
		memset(check, false, sizeof(check));
		memset(from, 0, sizeof(from));
		memset(how, 0, sizeof(how));
		cin >> x >> y;
		queue<int> q;
		q.push(x);
		check[x] = true;
		from[x] = -1;
		how[x] = ' ';
		while (!q.empty()) {
			int now = q.front();
			q.pop();
			int next = (now * 2) % 10000;
			if (next < 10000 && next > 0 && check[next] == false) {
				check[next] = true;
				from[next] = now;
				how[next] = 'D';
				q.push(next);
			}
			next = now-1;
			if (next == -1) next = 9999;
			if (next < 10000 && next > 0 && check[next] == false) {
				check[next] = true;
				from[next] = now;
				how[next] = 'S';
				q.push(next);
			}
			next = (now * 10) % 10000 + now / 1000;
			if (next <10000 && next > 0 && check[next] == false) {
				check[next] = true;
				from[next] = now;
				how[next] = 'L';
				q.push(next);
			}
			next = (now / 10) + (now % 10) * 1000;
			if (next < 10000 && next > 0 && check[next] == false) {
				check[next] = true;
				from[next] = now;
				how[next] = 'R';
				q.push(next);
			}
		}

		string ans = "";
		int i = y;
		while (i!=x){
			ans += how[i];
			i = from[i];
		}
		reverse(ans.begin(), ans.end());
		cout << ans << "\n";

	}
	return 0;
}