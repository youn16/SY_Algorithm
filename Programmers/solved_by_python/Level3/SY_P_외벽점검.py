'''
프로그래머스 - level3 : 외벽점검
파이썬 버전
by SY
DATE : 2020.10.16
'''
from itertools import permutations

def solution(n, weak, dist):
    ans = -1
    w_size = len(weak)
    d_size = len(dist)
    permut = list(permutations(dist))
    #print(permut)
    i = 0
    while i < w_size :
        if i != 0:
            tmp = weak[0]+n
            for j in range(1,w_size) :
                weak[j - 1] = weak[j]
            weak[w_size-1] = tmp
        i += 1 
        for word in permut :
            wcnt = 0
            for d in range(0,d_size) : 
                tmp = weak[wcnt]+word[d]
                while True :
                    if tmp >= weak[wcnt] :
                        wcnt += 1
                    elif tmp < weak[wcnt] :
                        break
                    if wcnt == w_size :
                        break
                if wcnt == w_size : 
                    if ans == -1 or ans > d+1 :
                        ans = d+1
                    break
    return ans