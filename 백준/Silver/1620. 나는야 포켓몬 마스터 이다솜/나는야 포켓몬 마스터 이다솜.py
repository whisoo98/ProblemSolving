import sys
input = sys.stdin.readline

n,m = map(int, input().split())
Pokemon = dict()

for i in range(n):
    pokemon = input().strip()
    Pokemon[str(i+1)] = pokemon
    Pokemon[pokemon] = i+1
    
for _ in range(m):
    quary = input().strip()
    print(Pokemon[quary])