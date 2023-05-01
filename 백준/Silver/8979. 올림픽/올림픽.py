import sys

input = sys.stdin.readline

n, target = map(int,input().split())
medals = [[] for _ in range(n+1)]

for i in range(n):
    country, g,s,b = map(int,input().split())
    medals[country]= [g,s,b,country]

medals.sort(reverse=True)
ranks = [[] for _ in range(n+10)]
ranks[1].append(medals[0][3])
rank=1
trank=0
for i in range(1,len(medals)-1):
    if medals[i][:-1] == medals[i-1][:-1]:
        ranks[rank].append(medals[i][-1])
        trank+=1 
    else:
        rank+=trank+1
        ranks[rank].append(medals[i][-1])
        trank= 0
for i in range(len(ranks)):
    if target in ranks[i]:
        print(i)
    
    