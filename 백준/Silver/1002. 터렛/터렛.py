import sys,math
input = sys.stdin.readline

T = int(input())
while T:
    T-=1
    x1,y1,r1,x2,y2,r2 = map(int,input().split())
    if x1==x2 and y1==y2:
        if r1==r2:
            print(-1)
        else:
            print(0)
    else:
        d = math.sqrt(abs(y1-y2)**2+abs(x1-x2)**2)
        if d> r1+r2:
            print(0)
        elif d == r1+r2:
            print(1)
        elif d == max(r1,r2)-min(r1,r2):
            print(1)
        elif d > max(r1,r2)-min(r1,r2):
            print(2)
        else:
            print(0)