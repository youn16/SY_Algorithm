'''
백준 11404번 - 플로이드
solved by SY
플로이드 알고리즘을 활용한 문제
파이썬으로 제출하니 시간초과나서 pypy3으로 제출, 그래도 cpp에 비하면 엄청난 시간이 소요된다...
DATE : 2020.09.27
'''
INF = 1e9+7
n = int(input())
m = int(input())
rel = [[0]*(n+1) for _ in range(n+1)]
for s in range(1,n+1):
    for e in range(1,n+1):
        if s==e : continue
        rel[s][e] = INF
for _ in range(m):
    s, e, val = map(int,input().split())
    if rel[s][e] > val:
        rel[s][e] = val
for t in range(1,n+1):
    for s in range(1,n+1):
        for e in range(1,n+1):
            rel[s][e] = min(rel[s][e],rel[s][t]+rel[t][e])
for s in range(1,n+1):
    for e in range(1,n+1):
        if rel[s][e]>=INF:
            print(0,end = ' ')
        else:
            print(rel[s][e],end=' ')
    print()
