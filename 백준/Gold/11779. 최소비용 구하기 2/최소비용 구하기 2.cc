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
#define N 1005
#define ll long long
#define endl "\n"
#define MID(a,b) (a+b)/2
#define INF 987654321
using namespace std;

vector<int> edge_vec[N];
int edge_mat[N][N];
int adj_mat[N];
int visit[N];
int V, E; 
int st, ed;

void dijkstra() {
	visit[st] = 0;
	priority_queue<pair<int, int>> pq;
	pq.push({ -visit[st],st });
	while (pq.size()) {
		int now = pq.top().second;
		int cost = -pq.top().first;
		pq.pop();
		if (cost > visit[now]) {
			continue;
		}
		for (auto next : edge_vec[now]) {
			int next_cost = edge_mat[now][next];
			if (visit[next] > cost + next_cost) {
				visit[next] = cost + next_cost;
				pq.push({ -visit[next],next });
				adj_mat[next] = now;
			}
		}
	}
}

vector<int> findRoute() {
	stack<int> path_stk;
	vector<int> route;
	path_stk.push(ed);
	int now = ed;
	while (now != st) {
		now = adj_mat[now];
		path_stk.push(now);
	}
	while (path_stk.size()) {
		route.push_back(path_stk.top());
		path_stk.pop();
	}
	return route;
}

void Solution() {
	dijkstra();
	vector<int> route = findRoute();
	cout << visit[ed] << endl;
	cout << route.size() << endl;
	for (auto path : route) {
		cout << path << " ";
	}
	cout << endl;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, j; //for문 변수 -> longlong필요한지 확인
	cin >> V >> E;
	for (int i = 1; i <= V; i++) {
		for (int j = 1; j <= V; j++) {
			edge_mat[i][j] = INF;
		}
		visit[i] = INF;
	}
	for (int i = 1; i <= E; i++) {
		int a, b, c; cin >> a >> b >> c;
		edge_vec[a].push_back(b);
		//edge_vec[b].push_back(a);
		edge_mat[a][b] = min(edge_mat[a][b], c);
		//edge_mat[b][a] = min(edge_mat[b][a], c);
	}
	cin >> st >> ed;
	Solution();
	return 0;
}