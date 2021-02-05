#include <iostream>
using namespace std;
/*
문제 그대로 구현하면 시간 초과가 난다.
투 포인트 알고리즘을 사용
*/
int arr[10001];

int main(){
    int N,M;
    cin >> N >> M;
    for(int i = 0; i < N; i++){
        cin >> arr[i];
    }
    int low = 0;
    int high = 0;
    int sum = arr[0];
    int res = 0;
    while(low <= high && high < N){
        if(sum < M){
            high +=1;
            sum += arr[high];
        }
        else if(sum == M){
            res+=1;
            high += 1;
            sum += arr[high];
        }
        else{
            sum -= arr[low];
            low += 1;
            if(low>high && low < N){
                high = low;
                sum = arr[low];
            }
        }

    }

    cout << res;

    return 0;
}