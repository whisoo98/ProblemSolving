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
#define INF 987654321
using namespace std;

vector<pair<int, int>> edge[2005];
vector<int> ans;
int visit[2005];
priority_queue<pair<int, int>> pq;
void dijk(int st) {
	visit[st] = 0;
	pq.push({ -visit[st],st });

	while (!pq.empty()) {
		int dist = -pq.top().first;
		int now = pq.top().second;
		pq.pop();
		for (auto it : edge[now]) {
			if (visit[it.second] > visit[now] + it.first) {
				visit[it.second] = visit[now] + it.first;
				pq.push({ -visit[it.second], it.second });
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, j; //for문 변수 -> longlong필요한지 확인
	int T; cin >> T;
	while (T--) {
		int n, m, t; cin >> n >> m >> t;
		int s, g, h; cin >> s >> g >> h;

		for (i = 1; i <= n; i++) {
			edge[i].clear();
			visit[i] = 987654321;
			ans.clear();
		}

		visit[s] = 0;

		for (i = 1; i <= m; i++) {
			int a, b, c; cin >> a >> b >> c;
			edge[a].push_back({ c,b });
			edge[b].push_back({ c,a });
		}

		int between = 0;
		for (auto it : edge[g]) {
			if (it.second == h) {
				between = it.first;
			}
		}
		
		for (i = 1; i <= t; i++) {
			for (j = 1; j <= n; j++) {
				visit[j] = INF;
			}
			int end; cin >> end;
			dijk(s);
			int ans1 = visit[end];
			int ans2 = visit[g];
			int ans3 = visit[h];

			for (j = 1; j <= n; j++) {
				visit[j] = INF;
			}
			dijk(g);
			ans3 += visit[end] + between;
			for (j = 1; j <= n; j++) {
				visit[j] = INF;
			}
			dijk(h);
			ans2 += visit[end] + between;
			if (ans1 == min(ans2, ans3)) ans.push_back(end);
		}







		
		sort(ans.begin(), ans.end());
		for (auto it : ans) cout << it << " ";
		cout << "\n";
	}

	return 0;
}