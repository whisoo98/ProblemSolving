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
#define N 100005
#define ll long long
#define INF 987654321000
#define endl "\n"
#define MID(a,b) (a+b)/2

using namespace std;

int ward[N];
ll visit[N];
priority_queue<pair<ll, int>>pq;
vector < pair<ll, int>> edge[N];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, j; //for문 변수 -> longlong필요한지 확인
	int n, m; cin >> n >> m;
	for (i = 0; i < n; i++) {
		cin >> ward[i];
		visit[i] = INF;
	}
	for (i = 1; i <= m; i++) {
		int a, b; ll c; cin >> a >> b >> c;
		//pq.push({ -c,a,b });
		//a++; b++;
		if (a == n-1 || b == n-1) {
			edge[a].push_back({ c,b });
			edge[b].push_back({ c, a });
		}
		else if (!ward[a] && !ward[b]) {
			edge[a].push_back({ c,b });
			edge[b].push_back({ c, a });
		}
	}
	visit[0] = 0;
	pq.push({ -0,0 });
	while (!pq.empty()) {
		ll dist = -pq.top().first;
		int now = pq.top().second;
		pq.pop();
        if (visit[now] < dist) continue;
		for (auto it : edge[now]) {
			int Next = it.second;
			ll cost = it.first;
			if (visit[Next] > dist + cost) {
				/*if (next == n) {
					visit[next] = dist + cost;
a					pq.push({ -visit[next],next });
				}
				else if (!ward[next]) {
					visit[next] = dist + cost;
					pq.push({ -visit[next],next });
				}*/
				visit[Next] = dist + cost;
				pq.push({ -visit[Next],Next });
			}
		}
	}
	if (visit[n-1] == INF) cout << -1;
	else cout << visit[n-1];
	return 0;
}