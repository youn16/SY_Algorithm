#include <iostream>
#define max(a,b) a>b?a:b
using namespace std;
int input[1001];
int R[1001];
int L[1001];
int main()
{
    int N;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> input[i];
    }
    R[0] = 1;
    for (int i = 1; i < N; i++)
    {
        for (int k = i - 1; k >= 0; k--)
        {
            if (input[k] < input[i])
            {
                R[i] = max(R[i],R[k] + 1);
            }
        }
        if (R[i] == 0)
            R[i] = 1;
    }
    L[N-1] = 1;
    for (int i = N-2; i >= 0; i--)
    {
        for (int k = i+1; k < N; k++)
        {
            if (input[k] < input[i])
            {
                L[i] = max(L[i],L[k] + 1);
            }
        }
        if (L[i] == 0)
            L[i] = 1;
    }
    int res = 0;
    for (int i = 0; i < N; i++)
    {
        res = max(res, R[i]+L[i]-1);
    }
    cout << res;
    return 0;
}