n = int(input())
answer = list(map(int,input().split()))
weight = 1
ans =0
for idx, i in enumerate(answer):
    if i:
        ans+=i*weight
        weight+=1
    else:
        weight =1
print(ans)
    