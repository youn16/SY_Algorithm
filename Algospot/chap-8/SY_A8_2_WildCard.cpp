/*
알고스팟 - 와일드카드
solved by SY
동적 계획 문제, 메모리제이션을 사용
DATE : 2020.10.02
*/
#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
string W, S;
int cache[101][101];
vector<string> v;
int WildCard(int w, int s) {
	int w_size = W.size();
	int s_size = S.size();

	//cache[w][s]는 W의 w부터 끝까지, S의 s부터 끝까지를
	//검사했을 때 둘이 상호 일치하는지 확인한 값을 저장한 배열이다
	//-1은 아직 모르는 경우, 0은 안되는 경우, 1은 되는 경우
	//reference by 종만북
	int& ret = cache[w][s];//&하면 주소값이 복사되지만, 평소 사용시 그냥 ret하는 경우 평범한 int로 사용됨, *(포인터와는 다르다)
	if (ret != -1) return ret;

	while (w < w_size && s < s_size && (W[w] == S[s] || W[w] == '?')) {
		w++; s++;
	}
	if (w == w_size) {
		if (s == s_size) { return ret = 1; }
		else { return ret = 0; }
	}
	if (W[w] == '*') {
		for (int skip = 0; s + skip <= s_size; skip++) {
			if (WildCard(w + 1, s + skip)) { return ret = 1; }
		}
	}
	return ret = 0;
}
int main(void) {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int t_c = 0;
	cin >> t_c;
	while (t_c--) {
		int n = 0;
		cin >> W;
		cin >> n;
		v.clear();
		for (int i = 0; i < n; i++) {
			cin >> S;
			memset(cache, -1, sizeof(cache));
			if(WildCard(0, 0)) v.push_back(S);
		}
		sort(v.begin(), v.end());
		for (int i = 0; i < v.size(); i++) {
			cout << v[i] << "\n";
		}
	}
	return 0;
}
