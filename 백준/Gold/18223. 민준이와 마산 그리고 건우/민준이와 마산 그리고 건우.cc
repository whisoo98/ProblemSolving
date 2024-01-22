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
#define N 5005
#define ll long long
#define endl "\n"
#define MID(a,b) (a+b)/2
#define INF 987654321
using namespace std;

vector<pair<int, int>> edge[N];
int visit[N];

void dijkstra(int V, int E, int st) {
	for (int i = 1; i <= V; i++) {
		visit[i] = INF;
	}
	visit[st] = 0;
	priority_queue<pair<int, int>> pq;
	pq.push({ -visit[st],st });

	while (pq.size()) {
		int now = pq.top().second;
		int cost = -pq.top().first;
		pq.pop();
		for (auto iter : edge[now]) {
			int next = iter.first;
			int next_cost = iter.second;
			if (visit[next] > cost + next_cost) {
				visit[next] = cost + next_cost;
				pq.push({ -visit[next],next });
			}
		}
	}
}

void Solution(int V, int E, int gunwoo) {
	
	int minjoon = 1;
	dijkstra(V, E, minjoon);
	int minjoon_to_end = visit[V];
	
	dijkstra(V, E, gunwoo);
	int gunwoo_to_minjoon = visit[minjoon];
	int gunwoo_to_end = visit[V];
	if (minjoon_to_end == gunwoo_to_minjoon + gunwoo_to_end) {
		cout << "SAVE HIM" << endl;
	}
	else {
		cout << "GOOD BYE" << endl;
	}

}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, j; //for문 변수 -> longlong필요한지 확인
	int V, E, gunwoo; cin >> V >> E >> gunwoo;
	for (int i = 0; i < E; i++) {
		int a, b, c; cin >> a >> b >> c;
		edge[a].push_back({ b,c });
		edge[b].push_back({ a,c });
	}
	Solution(V, E, gunwoo);
	return 0;
}