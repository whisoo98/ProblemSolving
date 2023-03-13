n,m = map(int,input().split())

def del1(N):
    N //=10
    return N

def div2(N):
    N //=2
    return N

cnt = 1
N=m
while True:
    if N==n:
        break
    if N<n:
        cnt=-1
        break
    if N%2==0:
        N=div2(N)
        cnt+=1
    elif N%10==1:
        N=del1(N)
        cnt+=1
    else:
        cnt = -1
        break

print(cnt)
