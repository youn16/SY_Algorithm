'''
프로그래머스 - level1
by SY
DATE : 2020.09.12
'''
def solution(s):
    return s.isdigit() and (len(s) == 4 or len(s) == 6)