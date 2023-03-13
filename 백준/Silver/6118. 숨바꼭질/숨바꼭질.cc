#include <iostream>
#include <algorithm>
#include <functional>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <string>
#include <queue>
#include <stack>
#include <map>
#include <vector>
#include <set>
#include <sstream>

using namespace std;

vector<int> edge[20005];
priority_queue<pair<int, int>> q;
int dist[20005];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, j; //for문 변수 -> longlong필요한지 확인
	int n, m; cin >> n >> m;
	for (i = 0; i < m; i++) {
		int a, b; cin >> a >> b;
		edge[a].push_back(b);
		edge[b].push_back(a);
	}
	for (i = 1; i <= n; i++) {
		dist[i] = 987654321;
	}
	int st = 1;
	dist[st] = 0;
	q.push({ -dist[st],st });
	while (!q.empty()) {
		int count = -q.top().first;
		int now = q.top().second;
		q.pop();
		int size = edge[now].size();
		for (i = 0; i < size; i++) {
			if (dist[edge[now][i]] > count + 1) {
				dist[edge[now][i]] = count + 1;
				q.push({ -dist[edge[now][i]],edge[now][i] });
			}
		}
	}
	int ans = max_element(dist + 1, dist + 1 + n) - dist;
	int cnt = count(dist + 1, dist + 1 + n, dist[ans]);
	cout << ans << " " << dist[ans] << " " << cnt;
	return 0;
}