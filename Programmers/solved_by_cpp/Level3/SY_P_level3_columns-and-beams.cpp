#include <string>
#include <vector>
#include <algorithm>

using namespace std;
bool cmp(vector<int>a, vector<int> b) {
	if (a[0] > b[0])return true;
	if (a[0] == b[0]) {
		if (a[1] > b[1]) return true;
	}
	return false;
}
int road[101][101];
vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
	vector<vector<int>> answer;

	for (vector<int> build : build_frame) {
		int x = build[0], y = build[1];
		int ch = build[2]; // 0 = 기둥 = 2, 1 = 보 = 3
		int dd = build[3]; // 0 = 삭제, 1 =  설치
		if (dd == 1) {
			if (y == 0 && ch == 0) {
				road[y][x] = 2;
				continue;
			}
			if (ch == 1) {//보
				if ((y!=0 && road[y - 1][x] == 2) || (y!=0&&x + 1 <= n && road[y - 1][x + 1] == 2)) {
					road[y][x] = 3;
					continue;
				}
				if ((x != 0 && road[y][x - 1] == 3) && (x != n && road[y][x + 1] == 3)) {
					road[y][x] = 3;
					continue;
				}
			}
			if (ch == 0) {
				if (y != 0 && (road[y - 1][x] == 2 || road[y - 1][x] == 3)) {
					road[y][x] = 2;
					continue;
				}
				if (y != 0 && x != 0 && road[y - 1][x - 1] == 3) {
					road[y][x] = 2;
					continue;
				}
			}
		}
		if (dd == 0) {
			if (ch == 1) {//보인 경우
				if (y != n && road[y + 1][x] == 2) { continue; }//위에 기둥있는 경우
				if (y != n && x != n && road[y + 1][x + 1] == 2) { continue; }
				if (x + 2 <= n && road[y][x + 1] == 3 && road[y][x + 2] == 3) { continue; }
				if (x - 2 >= 0 && road[y][x - 1] == 3 && road[y][x - 2] == 3) { continue; }
				road[y][x] = 0;
				continue;
			}
			if (ch == 0) {//기둥// 0 = 기둥 = 2, 1 = 보 = 3
				if (y != n && road[y + 1][x] == 2) { continue; }//위에 기둥있는 경우
				if (y != n && road[y + 1][x] == 3 && road[y][x + 1] != 2) {
					if (road[y + 1][x - 1] == 3&& road[y+1][x+1]==3) {
						road[y][x] = 0;
						continue;
					}
					else { continue; }
				}
				if (x + 2 <= n && road[y][x + 1] == 3 && road[y][x + 2] == 3) { continue; }
				if (x - 2 >= 0 && road[y][x - 1] == 3 && road[y][x - 2] == 3) { continue; }
				road[y][x] = 0;
				continue;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (road[i][j] == 3) { continue; }
			else if (road[i][j] == 2) {
				vector<int> tmp = { j,i,0 };
				answer.push_back(tmp);
			}
			else if (road[i][j] == 3) {
				vector<int> tmp = { j,i,1 };
				answer.push_back(tmp);
			}
		}
	}
	sort(answer.begin(), answer.end(), cmp);
	return answer;
}

int main() {
	int n = 5;
	vector<vector<int>> build_frame = { {0, 0, 0, 1},
		{2, 0, 0, 1},
		{4, 0, 0, 1},{0, 1, 1, 1},{1, 1, 1, 1},
		{2, 1, 1, 1},{3, 1, 1, 1},{2, 0, 0, 0},{1, 1, 1, 0},{2, 2, 0, 1} };
	solution(n, build_frame);
	return 0;
}