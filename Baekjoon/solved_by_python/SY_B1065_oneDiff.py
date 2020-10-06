'''
백준 1065 - 한수
solved by SY
c++로도 간단하게 나중에 구현하고 비교해 보기!
DATE : 2020.10.07
'''
n = int(input())
res = 0
for i in range(1,n+1) :
    l = [int(r) for r in str(i)]
    if len(l)==1 :
        res += 1
        continue
    diff = l[0]-l[1]
    flg = True
    for j in range(1,len(l)-1):
        if diff != l[j]-l[j+1]:
            flg = False
            break
    if flg :
        res += 1
print(res)



