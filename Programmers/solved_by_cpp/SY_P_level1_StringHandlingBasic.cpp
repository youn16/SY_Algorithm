'''
프로그래머스 - level1
by SY
DATE : 2020.09.12
'''
#include <string>
#include <vector>

using namespace std;

bool solution(string s) {

    int size = s.size();
    if(size == 4 || size == 6){
        for(int i =0;i<size;i++){
            if(s[i]>='0' && s[i]<='9'){return true;}
            else{return false;}
        }
    }
    return false;
}