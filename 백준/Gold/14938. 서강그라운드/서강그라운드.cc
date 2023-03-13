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
#define N 105
#define ll long long
#define endl "\n"
#define MID(a,b) (a+b)/2
#define INF 987654321
using namespace std;

int location[N];
vector<pair<int, int>> edge[N];
int dist[N][N];

void dijkstra(int n, int m, int range, int st) {
	dist[st][st] = 0;
	priority_queue<pair<int, int>> pq;
	pq.push({ -dist[st][st],st });
	while (pq.size()) {
		int now = pq.top().second;
		int cost = -pq.top().first;
		pq.pop();
		for (auto it : edge[now]) {
			int next = it.second;
			int next_cost = it.first;
			if (cost + next_cost > range) {
				continue;
			}
			if (dist[st][next] > cost + next_cost) {
				dist[st][next] = cost + next_cost;
				pq.push({ -dist[st][next],next });
			}
		}
	}
}
void Solution(int n, int range, int m) {
	int ans = -1;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			dist[i][j] = INF;
		}
		dijkstra(n, m, range,i);
		int temp = 0;
		for (int j = 1; j <= n; j++) {
			if (dist[i][j] <= range) {
				temp += location[j];
			}
		}
		ans = max(ans, temp);
	}
	cout << ans << endl;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, j; //for문 변수 -> longlong필요한지 확인
	int n, range, m; cin >> n >> range >> m;
	for (int i = 1; i <= n; i++) {
		cin >> location[i];
	}
	for (int i = 0; i < m; i++) {
		int a, b, c; cin >> a >> b >> c;
		edge[a].push_back({ c,b });
		edge[b].push_back({ c,a });
	}
	Solution(n, range, m);
	return 0;
}