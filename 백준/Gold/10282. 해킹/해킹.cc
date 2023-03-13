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
#define N 10005
using namespace std;

int dist[N];
vector<pair<int, int>> edge[N];


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, j; //for문 변수 -> longlong필요한지 확인
	int T; cin >> T;
	while (T--) {
		int n, m, st; cin >> n >> m >> st;
		if (cin.eof()) break;
		priority_queue<pair<int, int>> pq;
		for (i = 1; i <= n; i++) dist[i] = 987654321;
		for (i = 1; i <= m; i++) {
			int a, b, c; cin >> a >> b >> c;
			edge[b].push_back({ c,a });
		}
		dist[st] = 0;
		pq.push({ 0,st });
		
		while (!pq.empty()) {
			
			int val = -pq.top().first;
			int now = pq.top().second;
			pq.pop();
			
			for (auto it : edge[now]) {
				if (dist[it.second] > val + it.first) {
					dist[it.second] = val + it.first;
					pq.push({ -dist[it.second],it.second });
				}
			}
		}
		int cnt = 0;
		int MAX = -1;
		for (i = 1; i <= n; i++) {
			if (dist[i] != 987654321) {
				cnt++;
				MAX = max(MAX, dist[i]);
			}
		}
		cout << cnt << " " << MAX << "\n";

		for (i = 1; i <= n; i++) {
			dist[i] = 0;
			edge[i].clear();
		}
	}

	return 0;
}