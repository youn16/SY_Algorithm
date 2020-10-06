#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;
string solution(string s) {
    string ans = "";
    for (int i = 0; i < s.size();i++) {
        for (int j = 1;i<s.size(); j++,i++) {
            if (s.at(i) == ' ') { break; }
            if (j % 2 == 0) { ans += tolower(s[i]); }
            else { ans += toupper(s[i]); }
        }
        ans += " ";
    }
    return ans;
}

int main() {
    cout << solution("try hello world");
    return 0;
}