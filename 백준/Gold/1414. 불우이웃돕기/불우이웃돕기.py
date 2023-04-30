import sys, string
from queue import PriorityQueue
input = sys.stdin.readline
alphabet = string.ascii_lowercase
ALPHABET = string.ascii_uppercase
n = int(input())
pq = PriorityQueue()
lan = []
total = 0
par = [i for i in range(n)]
def Find(x):
    if par[x] == x:
        return x
    else:
        par[x] = Find(par[x])
        return par[x]
def Union(x,y):
    X = Find(x)
    Y = Find(y)
    if(X!=Y):
        par[Y]=X
        return 1
    return -1
        
def kruskal():
    global total
    while(pq.qsize()):
        # print(pq.qsize())
        cost, a, b = pq.get()
        # print(a,b)
        if Union(a,b) == 1:
            # print("cost : ",cost)
            total -= cost

def main():
    global total, lan, pq, par
    for _ in range(n):
        lan.append(input())
    for i in range(n):
        for j in range(n):
            if lan[i][j]=='0':
                # print(i,j)
                continue
            if (idx:=alphabet.find(lan[i][j])) != -1:
                total += idx+1
                idx = idx+1
            else:
                idx=ALPHABET.find(lan[i][j])
                total += idx+27
                idx = idx + 27
            if i != j:
                pq.put((idx,i,j))
    # print(total)
    kruskal()
    Set = set()
    for i in range(n):
        Set.add(Find(i))
    #     # print(par[i])
    # par = set(par)
    if(len(Set)>1):
        print(-1)
    else:
        print(total)
        
if __name__ == "__main__":
    main()