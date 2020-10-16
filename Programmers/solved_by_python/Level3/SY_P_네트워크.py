'''
프로그래머스 - level3 : 네트워크
by SY
DATE : 2020.10.16
'''
visited = [0 for _ in range(200)]
def dfs(r,n,mp):
    visited[r] = 1
    for i in range(0,n):
        if visited[i] == 0 and mp[r][i]==1 and r!=i:
            dfs(i,n,mp)
def solution(n, computers):
    answer = 0
    for i in range(0,n) :
        if visited[i] == 0:
            dfs(i,n,computers)
            answer += 1
    return answer