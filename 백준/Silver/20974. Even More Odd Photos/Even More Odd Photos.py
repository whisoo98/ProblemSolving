import sys

input = sys.stdin.readline

n = int(input())

ids = list(map(int,input().split()))
odds = []
evens = []

for id in ids:
    if id%2 == 0:
        evens.append(id)
    else:
        odds.append(id)

turn = 0
ans = 0
while len(odds) and len(evens):
    if turn == 0:
       ans+=1
       evens.pop()
       turn = 1
    else:
        ans+=1
        odds.pop()
        turn = 0

if len(odds):
    while len(odds)>1:
        if turn == 0:
            ans+=1
            odds.pop()
            odds.pop()
            turn = 1
        else:
            ans+=1
            odds.pop()
            turn = 0
    if len(odds):
        if turn == 1:
            ans +=1
        else:
            ans-=1
else:
    if turn == 0:
        ans+=1
print(ans) 



        