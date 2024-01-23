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
#define N 10'005
#define ll long long
#define endl "\n"
#define MID(a,b) (a+b)/2
#define INF 987654321
using namespace std;

vector<int> edge[N];
int dist[N];
int visit[N];


vector<int> dijkstra(int V, int E, int st, int ed) {
	vector<vector<int>> ret;
	int min_dist = INF;
	for (int i = 1; i <= V; i++) {
		dist[i] = INF;
	}
	dist[st] = 0;

	priority_queue<tuple<int, vector<int>, int>> pq;
	pq.push({ -dist[st],{st},st });
	while (pq.size()) {
		int cost = -get<0>(pq.top());
		vector<int> route = get<1>(pq.top());
		int now = get<2>(pq.top());
		pq.pop();

		if (cost > dist[now]) continue;
		if ((now == ed) && (min_dist >= route.size())) {
			if (min_dist > route.size()) {
				ret.clear();
				min_dist = route.size();
			}
			ret.push_back(route);
		}
		for (auto iter : edge[now]) {
			int next = iter;
			if (!visit[next] && (dist[next] >= cost + 1)) {
				dist[next] = cost + 1;
				vector<int> next_route = route;
				next_route.push_back(next);
				pq.push({ -dist[next], next_route, next });
			}
		}
	}
	/*ret.clear();
	ret.push_back({ 1,4,3 });
	ret.push_back({ 1,3,4 });*/
	sort(ret.begin(), ret.end(), less <vector<int>>());
	/*for (auto vec_iter : ret) {
		for (auto iter : vec_iter) {
			cout << iter << " ";
		}
		cout << endl;
	}*/
	return ret[0];
}

void Solution(int V, int E, int st, int ed) {
	vector<int> go_end = dijkstra(V, E, st, ed);
	int step_forward = go_end.size() - 1;
	for (auto node : go_end) {
		visit[node] = 1;
	}
	visit[st] = 0;
	visit[ed] = 0;

	vector<int> go_start = dijkstra(V, E, ed, st);
	int step_backward = go_start.size() - 1;
	cout << step_forward + step_backward << endl;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, j; //for문 변수 -> longlong필요한지 확인
	int V, E; cin >> V >> E;
	for (int i = 0; i < E; i++) {
		int a, b; cin >> a >> b;
		edge[a].push_back(b);
		edge[b].push_back(a);
	}
	int st, ed; cin >> st >> ed;
	Solution(V, E, st, ed);
	return 0;
}