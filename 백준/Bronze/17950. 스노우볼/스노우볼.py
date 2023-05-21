import sys

input = sys.stdin.readline

h, x = map(int,input().split())
snowballs = []
for _ in range(h):
    snowballs.append(int(input()))
ans = 0
for snowball in snowballs[::-1]:
    ans += snowball
    ans *= x
    ans %= int((1e9+7))
print(ans)