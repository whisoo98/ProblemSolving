human = 0
ans = -1
for _ in range(10):
    down, up = map(int,input().split())
    human -= down
    human += up
    ans = max(ans,human)
print(ans)