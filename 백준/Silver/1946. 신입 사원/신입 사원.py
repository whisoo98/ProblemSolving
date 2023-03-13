T = int(input())
while T:
    T-=1
    n = int(input())
    score = [0 for _ in range(n)]
    for i in range(n):
        a,b = map(int,input().split())
        score[i]=(a,b)
    score.sort()
    temp = score[0][1]
    for i,j in score[1:]:
        temp=min(temp,j)
        if j>temp:
            n-=1
    print(n)