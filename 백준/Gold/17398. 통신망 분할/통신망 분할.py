import sys

input = sys.stdin.readline

parent = [i for i in range(100_005)]
num_nodes = [1 for _ in range(100_005)]

def Find(x):
    global parent
    if x == parent[x]:
        return x
    parent[x] = Find(parent[x])
    return parent[x]

def Union(x, y):
    global num_nodes, parent
    x = Find(x)
    y = Find(y)
    nx = num_nodes[x]
    ny = num_nodes[y]
    if x==y:
        return 0
    if x!=y:
        parent[x] = y
        num_nodes[y] += num_nodes[x]
        return nx*ny

def main():
    n, m, q = map(int, input().split())
    # edge= [[] for _ in range(n+3)]
    edges = []
    
    for _ in range(m):
        a, b = map(int,input().split())
        # edge[a].append(b)
        # edge[b].append(a)
        edges.append((a,b))
    
    # query = []
    # for i in range(q):
    #     query.append(int(input()))
    queries = [int(input()) - 1 for _ in range(q)]
    queries.reverse()
    
    for idx, edge in enumerate(edges):
        if idx in queries:
            continue
        Union(edge[0],edge[1])
    
    ans = 0
    for query in queries:
        edge = edges[query]
        ans += Union(edge[0],edge[1])
    return ans

if "__main__" == __name__:
    print(main())