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


int edge[N][N];
vector<int> v[N];
int visit[N];
int sum[N];
vector<int> group[N];
int cnt;
void dfs(int x) {
	group[cnt].push_back(x);

	for (auto it : v[x]) {
		if (visit[it] == 0) {
			visit[it] = 1;
			dfs(it);
		}
	}

}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, j; //for문 변수 -> longlong필요한지 확인
	int n, m; cin >> n >> m;
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++) {
			if (i == j) edge[i][j] = 0;
			else edge[i][j] = INF;
		}
	}
	for (i = 1; i <= m; i++) {
		int a, b; cin >> a >> b;
		if (edge[a][b] != 1) {
			edge[a][b] = 1;
			edge[b][a] = 1;
			v[a].push_back(b);
			v[b].push_back(a);
		}
	}
	for (int k = 1; k <= n; k++) {
		for (i = 1; i <= n; i++) {
			for (j = 1; j <= n; j++) {
				if (edge[i][k] != INF && edge[k][j] != INF) {
					edge[i][j] = min(edge[i][j], edge[i][k] + edge[k][j]);
				}
			}
		}
	}
	
	
	vector<int> ans;
	for (i = 1; i <= n; i++) {
		if (visit[i] == 0) {
			cnt++;
			dfs(i);
			
		}
	}

	for (i = 1; i <= cnt; i++) {
		int MIN = INF;
		int idx;
		for (auto it1 : group[i]) {
			int MAX = -1;
			for (auto it2 : group[i]) {
				if (it1 == it2) continue;
				MAX = max(MAX, edge[it1][it2]);
			}
			if (MIN > MAX) {
				MIN = MAX;
				idx = it1;
			}
		}
		ans.push_back(idx);
	}
	cout << ans.size() << endl;
	sort(ans.begin(), ans.end());
	for (auto it : ans) {
		cout << it << endl;
	}
	return 0;
}