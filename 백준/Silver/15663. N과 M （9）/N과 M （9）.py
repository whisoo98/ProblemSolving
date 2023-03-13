n,m = map(int,input().split())
brr = list(map(int,input().split()))
brr.sort()
ans = set()
arr = list(range(n))

def comb(l, idx, lv):
    if lv == m:
        temp = []
        for i in l:
            temp.append(brr[i])
        ans.add(tuple(temp))
        return 0
    if idx >= len(arr):
        return 0
    for i in range(0, len(arr)):
            if arr[i] in l:
                continue
            l.append(arr[i])
            comb(l,0,lv+1)
            l.pop()

comb([],0,0)
ans = list(ans)
ans.sort()
for l in ans:
    for i in l:
        print(i, end = ' ')
    print()
