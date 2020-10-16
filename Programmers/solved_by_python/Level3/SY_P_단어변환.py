'''
프로그래머스 - level3 : 단어변환
by SY
DATE : 2020.10.16
'''
visited = [0 for _ in range(0,51)]
def find(front, words, num, nn) :
    res = []
    for i in range(len(words)):
        flg = True
        if visited[i] == 0 :
            for k in range(len(front)) :
                if k == num :
                    continue
                else :
                    if words[i][k]!=front[k] :
                        flg = False
            if flg:
                res.append([i,words[i]])
                visited[i] = visited[nn]+1
    return res
                        
def solution(begin, target, words):
    ans = 0
    if target not in words :
        return 0
    words.insert(0, begin)
    w_len = len(words)
    b_len = len(begin)
    que = [[0,begin]]
    visited[0] = 1
    while que :
        front = que.pop(0)
        print(front)
        for i in range(0,b_len):
            ret = find(front[1], words, i,front[0])
            for rr in ret:
                que.append(rr);
    ans = visited[words.index(target)]-1
    return ans