n,m = map(int,input().split())
arr = list(map(int,input().split()))
arr.sort()
def comb(l, idx, lv):
    if lv==m:
        for i in l:
            print(i, end =' ')
        print()
        return None
    if idx == len(arr):
        return None
    for i in range(idx, len(arr)):
        l.append(arr[i])
        comb(l,i,lv+1)
        l.pop()

comb([],0,0)
