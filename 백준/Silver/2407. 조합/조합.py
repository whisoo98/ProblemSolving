n,m = map(int,input().split())
#a = int(input())
#b = int(input())

dp = list()

for i in range(0,105):
    dp.append(list())
    if i==0:
        for j in range(105):
            dp[i].append(1)
    for j in range(105):
        if j == 0:
            dp[i].append(1)
        elif j>=i:
            dp[i].append(1)
        else:
            dp[i].append(dp[i-1][j-1]+dp[i-1][j])

print(dp[n][m])
