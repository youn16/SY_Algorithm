'''
프로그래머스 - level1
by SY
DATE : 2020.09.11
'''

move_x = [1,-1,0,0]
move_y = [0,0,1,-1]
def rec(loc,cnt,board):
    res = []
    if loc[1] == 1 :#가로
        if loc[0]==len(board) and loc[1]==len(baord) :
            return cnt
        if loc[0]==len(board) and loc[1]+1 == len(board) :
            return cnt
        for i in range(0, 3):
            cur = [loc[0][0]+move_y[i],loc[0][1]+move_y[i]]
            if board[cur[0]][cur[1]]!=1 and board[cur[0]][cur[1]+1]!= 1:
                res.append(rec([cur,1],cnt+1,board))
        cur = [loc[0][0]+0,loc[0][1]+1]
        if board[cur[0]][cur[1]]!=1 and board[cur[0]+1][cur[1]]!= 1:
            res.append(rec([cur,0],cnt+1,board))
        cur = [loc[0][0]-1,loc[0][1]+1] 
        if board[cur[0]][cur[1]]!=1 and board[cur[0]+1][cur[1]]!= 1:
            res.append(rec([cur,0],cnt+1,board))
    else :#세로
        if loc[0]==len(board) and loc[1]==len(baord) :
            return cnt
        if loc[0]+1==len(board) and loc[1]==len(board) :
            return cnt
        for i in range(0,3):
            cur = [loc[0][0]+move_y[i],loc[0][1]+move_y[i]]
            if board[cur[0]][cur[1]]!=1 and board[cur[0]+1][cur[1]]!= 1:
               res.append(rec([cur,0],cnt+1,board))
        cur = loc
        if board[cur[0]][cur[1]]!=1 and board[cur[0]][cur[1]+1]!= 1:
            res.append(rec([cur,1],cnt+1,board))
        cur = [loc[0][0],loc[0][1]-1] 
        if board[cur[0]][cur[1]]!=1 and board[cur[loc[0]][loc[1]]!= 1:
            res.append(rec([cur,0],cnt+1,board))

    return minx(res)
    


def solution(board):
    answer = 0
    anwser = rec([[1,1],1],0,board)
    return answer

board = [[0, 0, 0, 1, 1],[0, 0, 0, 1, 0],[0, 1, 0, 1, 1],[1, 1, 0, 0, 1],[0, 0, 0, 0, 0]]

print(solution(board))