#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cstdlib>

using namespace std;

bool cmp(int h, int m, int hh, int mm) {//h,m���� ũ�� false
    if (h > hh)
    {
        return true;
    }
    if (h == hh) {
        if (m >= mm)return true;
    }
    return false;
}
string to_s(int h, int m) {
    string hh = "";
    string mm = "";
    if (m < 0) { h -= 1; m += 60; }
    if (h / 10 == 0) { hh = '0' + to_string(h); }
    else { hh = to_string(h); }
    if (m / 10 == 0) { mm = '0' + to_string(m); }
    else { mm = to_string(m); }
    return hh + ":" + mm;
}

string solution(int n, int t, int m, vector<string> timetable) {
    string answer = "";
    sort(timetable.begin(), timetable.end());
    int t_size = timetable.size();
    int k = 0; int i = 0; int g = 0;//k: timtable ����, g: m����
    for (; i < n; i++) {
        int h = (i * t) / 60 + 9; int mn = (i * t) % 60;
        if (h >= 23 && mn >= 59) { i = i - 1; break; }
        g = 0;
        while (k < t_size && g < m) {
            int hh = atoi(timetable[k].substr(0, 2).c_str());
            int mm = atoi(timetable[k].substr(3, 2).c_str());
            if (hh >= 23 && mm >= 59) { break; }
            if (!cmp(h, mn, hh, mm)) { break; }//���ؽú��� �� ũ�� 
            k++; g++;
        }
    }

    if (g == m) {
        int hh = atoi(timetable[k - 1].substr(0, 2).c_str());
        int mm = atoi(timetable[k - 1].substr(3, 2).c_str());
        answer = to_s(hh, mm - 1);
    }
    else
    {
        if (i == n) { i = i - 1; }
        int h = (i * t) / 60 + 9; int mn = (i * t) % 60;
        answer = to_s(h, mn);
    }
    return answer;
}

int main() {
    //vector<string> timetable = { "09:10", "09:09", "08:00" };
   //vector<string> timetable = { "23:59" };
    vector<string> timetable = {"09:00","09:00","09:00","09:00" };

    cout << solution(2, 1, 2, timetable);
    
    return 0;
}