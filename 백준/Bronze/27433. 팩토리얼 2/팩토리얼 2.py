n = int(input())
if n ==0:
    print(1)
else:
    ans = 1;
    for i in range(n):
        ans *= (i+1)
    print(ans)