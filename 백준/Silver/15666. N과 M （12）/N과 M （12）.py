n,m = map(int,input().split())
brr = list(map(int,input().split()))
brr.sort()
ans = set()

def comb(l, idx, lv):
    if lv == m:
        temp = []
        for i in l:
            temp.append(brr[i])
        ans.add(tuple(temp))
        return None
    for i in range(idx, len(brr)):
        l.append(i)
        comb(l,i,lv+1)
        l.pop()

comb([],0,0)
ans = list(ans)
ans.sort()

for l in ans:
    for i in l:
        print(i, end=' ')
    print()
