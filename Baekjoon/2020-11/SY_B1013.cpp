#include <iostream>
using namespace std;
int tr[10][2]={
    {5,1},//0
    {2,9},//1
    {3,9},//2
    {3,4},//3
    {5,7},//4
    {9,6},//5
    {5,1},//6
    {8,7},//7
    {3,6},//8
    {9,9}//9
};
bool check(char *input){
    int state = 0;
    for(int i = 0; input[i];i++){
        int idx = input[i]-'0';
        state = tr[state][idx];
    }
    return state == 6 or state == 7 or state == 4 ;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int t;
    cin >> t;
    while(t--){
    char input[202];
    cin >> input;
    if(check(input)) cout << "YES" << "\n";
    else cout << "NO" << "\n";
    }
    return 0;
}