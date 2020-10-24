'''
백준
by SY
DATE : 2020.09.22
'''
from sys import stdin
MOD = 1e9+7
N,M,P = map(int, stdin.readline().split())
dp = [[0]*101 for _ in range(101)]
def solve():
    dp[0][0] = 1
    for i in range(1,P+1):
        for j in range(1,N+1):
            if j>0:
                dp[i][j]+=(dp[i-1][j-1]*(N-j+1))%MOD
            if j>M:
                dp[i][j]+=(dp[i-1][j]*(j-M))%MOD
    print(int(dp[P][N]%MOD))

solve()