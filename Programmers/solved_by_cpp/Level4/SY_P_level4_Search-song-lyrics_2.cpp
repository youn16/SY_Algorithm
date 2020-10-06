#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(string a, string b) {
	if (a.size() < b.size()) { return true; }
	else if (a.size() == b.size()) { if (a <= b)return true; }
	return false;
}
int check(string query, vector<string> words) {
	int answer = 0;
	int mid;
	int left = 0;
	int right = words.size() - 1;
	int res = -1;
	while (left <= right) {
		mid = (left + right) / 2;
		if (words[mid].size() == query.size()) {
			bool flg = true;
			int i;
			for (i = 0; i < query.size(); i++) {
				if (query[i] != '?') {
					if (query[i] != words[mid][i]) { flg = false; }
				}
				else { break; }
			}
			if (flg) {
				right = mid; res = mid;
				if (left == right) { break; }
			}
			else {
				if (words[mid].substr(0, i) > query.substr(0, i)) { right = mid - 1; }
				else { left = mid + 1; }
			}
		}
		else if (words[mid].size() < query.size()) { if (left == right) { break; }left = mid + 1; }
		else { if (left == right) { break; }right = mid - 1; }
	}
	if (res != -1) {
		int tmp = res;
		while (words[tmp].size() == query.size()) {
			bool flg = true;
			for (int i = 0; i < query.size(); i++) {
				if (query[i] != '?') {
					if (query[i] != words[tmp][i]) { flg = false; }
				}
				else { break; }
			}
			if (flg) { tmp++; }
			else { break; }
		}
		answer = (tmp - res);
	}
	return answer;
}
vector<int> solution(vector<string> words, vector<string> queries) {
	vector<int> answer;
	vector<string> re_words;
	for (string word : words)
	{
		re_words.push_back(word);
	}
	for (int i = 0; i < re_words.size(); i++)
	{
		reverse(re_words[i].begin(), re_words[i].end());
	}
	sort(re_words.begin(), re_words.end(), cmp);
	sort(words.begin(), words.end(), cmp);
	for (string query : queries) {
		if (query[0] == '?') {
			reverse(query.begin(), query.end()),
				answer.push_back(check(query, re_words));
		}
		else {
			answer.push_back(check(query, words));
		}
	}
	return answer;
}

int main() {

	vector<string> words = { "frodo", "front", "frost", "frozen", "frame", "kakao" };
	vector<string> queries = { "fro???" };

	/*
	vector<string> words = { "a","ab","ac","bac","bbb","c","ca","cab","bb" };
	vector<string> queries = { "a??","??b" };
	*/
	vector<int> a = solution(words, queries);
	for (int i : a) {
		cout << i << "\n";
	}
	return 0;
}