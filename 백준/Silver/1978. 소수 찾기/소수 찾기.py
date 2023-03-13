n = int(input())
l  = list(input().split())

def era():
    prime = [1 for _ in range(1001)]
    prime[1]=0
    prime[0]=0
    for i in range(2,100):
        if prime[i]==0:
            continue
        for j in range(i*i,1001,i):
            prime[j]=0
    return prime
prime = era()
count = 0
for ele in l:
    if prime[int(ele)]:
        count+=1

print(count)


