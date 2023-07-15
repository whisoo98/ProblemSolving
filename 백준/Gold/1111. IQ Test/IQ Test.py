import sys
import math
input = sys.stdin.readline

def main():
    n = int(input())
    l = list(map(int,input().split()))
    if n<3:
        if n==2:
            if l[0] == l[1]:
                print(l[0])
                return 0
        print('A')
        return 0
    b0 = l[1]-l[0]
    b1 = l[2]-l[1]
    if b0==0:
        if l.count(l[0]) == len(l):
            print(l[0])
            return 0
        else:
            print('B')
            return 0
    r = b1 // b0
    cmp_r = math.ceil(b1/b0)
    if r != cmp_r:
        print('B')
        return 0
    bn_1 = b1
    chk = 0
    for i in range(2,len(l)-1):
        bn = l[i+1]-l[i]
        if bn_1*r == bn:
            bn_1 = bn
            continue
        chk =1
        break
    if chk:
        print('B')
        return 0
    else:
        print(r*l[-1] + l[1]-r*l[0])
        return 0

if "__main__" == __name__:
    # while True:
    #     main()
    main()