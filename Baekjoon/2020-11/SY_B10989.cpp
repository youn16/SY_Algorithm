#include <iostream>
using namespace std;
int N;
int input[10001];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin >> N;
    for(int i = 0; i< N; i++){
        int idx = 0;
        cin >> idx;
        input[idx] += 1;
    }
    for(int i = 0; i< 10001; i++){
        if(input[i]!=0){
            for(int k = 0; k < input[i]; k++){
                cout << i <<"\n";
            }
        }
    }
    return 0;
}