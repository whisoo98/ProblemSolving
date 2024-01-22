import heapq
import sys

input = sys.stdin.readline

visit= []
INF = 987654321

def main():
    V, E, gunwoo = map(int, input().split())
    edges = [[] for _ in range(V + 5)]
    for _ in range(E):
        a, b, c = map(int, input().split())
        edges[a].append((b, c))
        edges[b].append((a, c))
    
    Solution(V,E,gunwoo,edges)

def Solution(V,E,gunwoo,edges):
    global visit
    minjoon = 1
    dijkstra(V,E,edges, minjoon)    
    minjoon_to_end = visit[V]
    
    dijkstra(V,E,edges, gunwoo)
    gunwoo_to_minjoon = visit[minjoon]
    gunwoo_to_end = visit[V]
    
    if minjoon_to_end == gunwoo_to_end+gunwoo_to_minjoon:
        print("SAVE HIM")
    else:
        print("GOOD BYE")

def dijkstra(V,E,edges, st):
    global visit, INF
    visit = [INF for _ in range(V+5)]
    visit[st] = 0
    pq = []
    heapq.heappush(pq,(-visit[st],st))
    while(len(pq)):
        cost, now  = pq.pop()
        cost = -cost
        
        if cost > visit[now]:
            continue
        
        for edge in edges[now]:
            next = edge[0]
            next_cost =edge[1]
            if visit[next] > cost + next_cost:
                visit[next] = cost + next_cost
                heapq.heappush(pq,(-visit[next],next))
    
if __name__ == "__main__":
    main()
