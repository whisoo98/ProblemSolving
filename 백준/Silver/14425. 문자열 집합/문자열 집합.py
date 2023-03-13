import sys
input = sys.stdin.readline

n,m = map(int, input().split())
strings = set()
for _ in range(n):
    strings.add(input().strip())

chk = 0
for _ in range(m):
    line = input().strip()
    if line in strings:
        chk+=1

print(chk)
    