import sys

input = sys.stdin.readline

parent = [i for i in range(100_005)]
num_nodes = [1 for i in range(100_005)]
MOD = 1_000_000_000
# unconnect = 1
before =0

def n_xC2(x):
    return (x * (x-1))//2

def Find(x):
    global parent
    if x == parent[x]:
        return x
    parent[x] = Find(parent[x])
    return parent[x]

def Union(x, y):
    global num_nodes, parent, before
    x = Find(x)
    y = Find(y)
    if x == y:
        # return (num_nodes[x] * (num_nodes[x]-1))//2
        # ret = n_xC2(num_nodes[x])
        ret = before
        return ret
    else:
        # hap = num_nodes[y] + num_nodes[x]
        # ret = (hap * (hap-1))//2
        ret = 0
        # if num_nodes[y]>1:
        #     ret += n_xC2(num_nodes[y])
        # if num_nodes[x]>1:
        #     ret += n_xC2(num_nodes[x])
        ret += before
        ret += num_nodes[y] * num_nodes[x]
        before = ret
        
        # temp = ret
        
        parent[x] = y
        num_nodes[y] += num_nodes[x]
        # if num_nodes[y] == n:
        #     unconnect = 0
        return ret

def main():
    global MOD
    global n
    ans = 0
    # total = 0
    n, m = map(int,input().split())
    edges = []
    for _ in range(m):
        a, b, cost = map(int,input().split())
        # total += cost
        edges.append((cost,a,b))
    edges.sort(reverse=True)
    
    for cost, a, b in edges:
        ret = Union(a,b)
        ans += cost * ret
        # print("cost : ", cost, "ret : ",ret, "added : ", cost*ret)
        # total -= cost
    print(ans%MOD)

if __name__ == "__main__":
    main()