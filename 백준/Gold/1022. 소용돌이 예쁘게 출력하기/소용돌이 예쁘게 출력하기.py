import sys

input = sys.stdin.readline

r1,c1,r2,c2 = map(int,input().split())
addy = -r1
addx = -c1
r1 += addy
r2 += addy
c1 += addx
c2 += addx

arr = [[0 for _ in range(55)] for _ in range(55)]

sty = addy
stx = addx
num = 1
sign = 1

def isok(ty,tx):
    # print(ty,tx)
    if ty<0 or ty > r2 or tx<0 or tx > c2:
        return False
    return True

if isok(sty,stx):
    arr[sty][stx] = num
# print (r2,c2)

length = 0
for k in range(1,10005):
    if arr[r1][c1] and arr[r2][c2]:
        break
    for i in range(1,k+1):
        stx = stx + sign*1
        num+=1
        if isok(sty,stx):
            arr[sty][stx] = num
            length = max(length, len(str(num)))
    sign *= -1
    for i in range(1,k+1):
        sty = sty + sign*1
        num+=1
        if isok(sty,stx):
            arr[sty][stx] = num
            length = max(length, len(str(num)))

for i in range(r1,r2+1):
    for j in range(c1,c2+1):
        print('{0:>{1}}'.format(arr[i][j],length), end = ' ')
    print()

    