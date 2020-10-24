#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
int t;
int prime[10000];
int visited[10000];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> t;
	prime[0] = 1;
	prime[1] = 1;
	for (int i = 2; i * i <= 9999; i++) {
		if (prime[i] == 0) {
			for (int j = 2; i * j <= 9999; j++) {
				prime[i * j] = 1;
			}
		}
	}

	while (t--) {
		int start, end;
		cin >> start >> end;
		fill(visited, visited + 10000, 0);
		queue<int> q;
		q.push(start);
		visited[start] = 1;
		while (!q.empty()) {
			int num = q.front();
			int cost = visited[num] + 1;
			q.pop();
			for (int i = 1; i <= 1000; i = i * 10) {
				for (int j = 0; j < 10; j++) {
					if (i == 1000 && j == 0) { continue; }
					int tmp = num - ((num % (i * 10)) / i) * i;
					tmp += j * i;
					if (prime[tmp] == 0) {
						if (visited[tmp] == 0 || cost < visited[tmp]) {
							q.push(tmp);
							visited[tmp] = cost;
						}
					}
				}
			}
		}
		if (visited[end] == -1) {
			cout << "Impossible" << "wn";
		}
		else {
			cout << visited[end] - 1 << "\n";
		}
	}

	return 0;
}