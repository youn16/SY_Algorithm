'''
프로그래머스 - level2_타겟넘버
by SY
DFS를 활용하여 풀음.
프로그래머스 1등 코드가 아주 멋짐...
DATE : 2020.09.30
'''
def dfs(numbers, idx, target, res):
    if idx==len(numbers) and res == target:
        return 1;
    if idx==len(numbers):
        return 0;
    return dfs(numbers,idx+1,target, res+numbers[idx]) + dfs(numbers,idx+1,target, res-numbers[idx])
def solution(numbers, target):
    answer = dfs(numbers, 0, target, 0)
    return answer
