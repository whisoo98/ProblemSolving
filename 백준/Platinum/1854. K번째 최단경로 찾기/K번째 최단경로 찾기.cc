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

vector<int> dist[N];
int cnt[N];
vector<pair<int, int>> edge[N];
priority_queue<pair<int, int>> pq;

void dijkstra(int st, int n, int k) {
	dist[st].push_back(0);
	pq.push({ -0,st });
	while (pq.size()) {
		int now = pq.top().second;
		int cost = -pq.top().first;
		pq.pop();
		if (cnt[now] == k) continue;
		cnt[now]++;
		for (auto it : edge[now]) {
			int next = it.second;
			//if (cnt[next]<k) {
				dist[next].push_back(cost + it.first);
				//dist[next] = cost + dist[it.first];
				pq.push({ -(cost + it.first),next });
			//}
		}
	}
}


void Solution(int st, int n,int k) {
	dijkstra(st, n,k);
	for (int i = st; i <= n; i++) {
		sort(dist[i].begin(), dist[i].end());
		if (cnt[i] >= k) cout << dist[i][k - 1] << endl;
		else cout << -1 << endl;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, j; //for문 변수 -> longlong필요한지 확인
	int n, m, k;
	cin >> n >> m >> k;
	for (int i = 0; i < m; i++) {
		int a, b, c; cin >> a >> b >> c;
		edge[a].push_back({ c,b });
	}
	int st = 1;
	Solution(st, n,k);
	return 0;
}