/*
백준 - B6209 : 제자리 멀리뛰기
solved by SY
수학
DATE : 2020.10.08
*/
#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long
using namespace std;
int d,n,m;
vector<int> v;
bool check(ll mid){
    int cnt = 0;
    int idx = 0;
    for(int i = 1; i<n+2;++i){
        ll diff = v[i]-v[idx];
        if(diff>=mid) {
            idx = i;
        }
        else{
            if((++cnt)>m){
                return false;
            }
        }
    }
    return true;
}
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin >> d >> n >> m;
    v.push_back(0);v.push_back(d);
    for(int i =0; i<n; i++){
        int t;
        cin >> t;
        v.push_back(t);
    }
    sort(v.begin(),v.end());
    ll left = 0, right =v[n+1];
    ll res = -1;
    while(left < right){
        ll mid = (left + right)/2+1;
        bool c = check(mid);
        if(c){
            left = mid;
            res = mid;
        }else{
            right = mid-1;
        }
    }
    cout << res;
    return 0;
}