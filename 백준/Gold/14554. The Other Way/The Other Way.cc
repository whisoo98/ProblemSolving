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
#define N 100'005
#define ll long long
#define endl "\n"
#define MID(a,b) (a+b)/2
#define MOD ((int)(1e9+9))
using namespace std;


vector<pair<ll, int>> edge[N];
int V, E;
ll visit[N];
int num_path[N];
int st, ed;




void dijkstra() {

	priority_queue<pair<ll, int>> pq;
	
	for (int i = 1; i <= V; i++) {
		visit[i] = LLONG_MAX;
	}

	visit[st] = 0;
	num_path[st] = 1;
	pq.push({ -visit[st],st });
	while (pq.size()) {
		ll cost = -pq.top().first;
		int now = pq.top().second;
		pq.pop();
		if (visit[now] < cost) continue;
		for (auto it : edge[now]) {
			ll next_cost = it.first;
			int next = it.second;
			if (visit[next] > cost + next_cost) {
				visit[next] = cost + next_cost;
				pq.push({ -visit[next], next });
				num_path[next] = num_path[now];
			}
			else if (visit[next] == cost + next_cost) {
				num_path[next] = (num_path[next] + num_path[now]) % MOD;
			}
		}
	}
}

void Solution() {
	dijkstra();
	cout << num_path[ed] % MOD << endl;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, j; //for문 변수 -> longlong필요한지 확인
	cin >> V >> E;
	cin >> st >> ed;
	for (int i = 0; i < E; i++) {
		int s, e; ll c; cin >> s >> e >> c;
		edge[s].push_back({ c,e });
		edge[e].push_back({ c,s });
	}
	Solution();
	return 0;
}