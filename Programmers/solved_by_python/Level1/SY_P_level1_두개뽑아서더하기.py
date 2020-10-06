'''
프로그래머스 - level1_두 개 뽑아서 더하기
by SY
조합으로 풀어도 될 것 같지만 간단하게 이중 포문을 사용
from itertools import combinations
l = list(combinations(numbers, 2))
DATE : 2020.09.28
'''
def solution(numbers):
    answer = []
    size = len(numbers)
    for i in range(0,size) :
        for j in range(i+1,size) :
            answer.append(numbers[i]+numbers[j])
    mset = set(answer)
    answer = list(mset)
    answer.sort()
    return answer
