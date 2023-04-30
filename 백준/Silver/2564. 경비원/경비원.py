import sys
input = sys.stdin.readline
x,y = map(int,input().split())
n = int(input())
shops = []

for i in range(n+1):
    dir, loc = map(int,input().split())
    if dir == 1:
        yy = 0
        xx = loc
    elif dir == 2:
        yy = y
        xx = loc
    elif dir == 3:
        xx = 0
        yy = loc
    elif dir ==4:
        xx = x
        yy = loc
    if i == n:
        security = (yy,xx,dir)
    else:
        shops.append((yy,xx,dir))

ans = 0
for shop in shops:
    yy = shop[0]
    xx = shop[1]
    dir = shop[2]
    dist=0
    if security[2]>2: # west or east
        if dir>2: # parallel
            if dir == security[2]: # at the same line
                dist += abs(yy-security[0])
            else: # at the parallel line
                dist += x
                dist += min(abs(y-yy) + abs(y-security[0]),
                            abs(yy) + abs(security[0]))
        else: # orthogonal
            dist += abs(xx-security[1]) + abs(yy-security[0])
    else: # north or south
        if dir<3: # parallel
            if dir == security[2]: # at the same line
                dist += abs(xx-security[1])
            else: # at the parallel line
                dist += y
                dist += min(abs(x-xx) + abs(x-security[1]),
                            abs(xx) + abs(security[1]))
        else: # orthogonal
            dist += abs(xx-security[1]) + abs(yy-security[0])
    # print(dist)
    ans += dist
print(ans)
    