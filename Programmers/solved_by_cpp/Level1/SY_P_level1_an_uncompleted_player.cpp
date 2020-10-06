#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    sort(participant.begin(), participant.end());
    sort(completion.begin(),completion.end());
    for (int i = 0; i < participant.size(); i++) {
        if (completion[i] != participant[i]) { answer = participant[i]; break; }
    }
    return answer;
}
int main() {
    vector<string> participant = { "mislav", "stanko", "mislav", "ana" }; vector<string> completion = { "stanko", "ana", "mislav" };
    cout << solution(participant, completion);
    return 0;
}