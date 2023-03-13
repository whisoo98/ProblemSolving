n = int(input())
ans = -1
for _ in range(n):
    l = [0 for _ in range(7)]
    a,b,c = map(int,input().split())
    l[a]+=1
    l[b]+=1
    l[c]+=1
    temp = 0
    tans = 0
    for i in range(1,7):
        if temp <= l[i]:
            temp = l[i]
            idx = i
    if temp == 1:
        tans = idx*100
    elif temp ==2:
        tans = 1000+idx*100
    else:
        tans = 10000+idx*1000
    ans = max(ans,tans)
print(ans)
        
