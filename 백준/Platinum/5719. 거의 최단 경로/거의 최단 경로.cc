#include <iostream>
#include <algorithm>
#include <functional>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <string>
#include <queue>
#include <stack>
#include <map>
#include <vector>
#include <set>
#include <sstream>
#include <ctime>
#include <climits>
#include <tuple>
#define N 505
#define ll long long
#define endl "\n"
#define MID(a,b) (a+b)/2
#define INF 987654321
using namespace std;

int edge[N][N];
int dist[N];
bool visit[N];
vector<int> before[N];

void dijkstra(int st, int ed, int n) {
	priority_queue<pair<int, int>> pq;
	dist[st] = 0;
	pq.push({ -dist[st],st });
	while (pq.size()) {
		int now = pq.top().second;
		int cost = -pq.top().first;
		pq.pop();
		if (now == ed) break;
		for (int next = 0; next < n; next++) {
			if (edge[now][next] == INF) continue;
			if (dist[next] >= cost + edge[now][next]) {
				if (dist[next] == cost + edge[now][next]) {
					before[next].push_back(now);
				}
				else {
					dist[next] = cost + edge[now][next];
					before[next].clear();
					before[next].push_back(now);
					pq.push({ -dist[next],next });
				}
			}
		}
	}
}

void deleteEdge(int st, int ed, int n, int node) {
	visit[node] = true;
	if (node == st) return;
	for (int pre : before[node]) {
		edge[pre][node] = INF;
		if (!visit[pre]) {
			deleteEdge(st, ed, n, pre);
		}
	}
}

void resetDist(int n) {
	for (int i = 0; i < n; i++) {
		dist[i] = INF;
		before[i].clear();
	}
}

void Solution(int st, int ed, int n) {
	dijkstra(st, ed, n);
	deleteEdge(st, ed, n,ed);
	resetDist(n);
	dijkstra(st, ed, n);
	dist[ed] = dist[ed] == INF ? -1 : dist[ed];
	cout << dist[ed] << endl;
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, j; //for문 변수 -> longlong필요한지 확인
	while (1) {
		int n, m; cin >> n >> m;
		if (n + m == 0) break;
		int s, d; cin >> s >> d;
		for (int i = 0; i < n; i++) {
			dist[i] = INF;
			before[i].clear();
			visit[i] = false;
			for (int j = 0; j < n; j++) {
				edge[i][j] = INF;
			}
		}
		for (int i = 0; i < m; i++) {
			int a, b, c; cin >> a >> b >> c;
			edge[a][b] = c;
		}
		Solution(s, d, n);
	}

	return 0;
}