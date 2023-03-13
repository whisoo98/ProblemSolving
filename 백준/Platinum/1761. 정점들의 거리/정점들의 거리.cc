#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <functional>
#include <stdlib.h>
#include <string>
#include <queue>
#include <stack>
#include <map>
#include <climits>
#include <cstring>


using namespace std;

/*struct type_name {

}srt;*/

//vector <type> vec;
//stack <type> stk;
//queue <type> q;
//string str;
//map <key_type,value_type> m;
vector<pair<int, int>>edge[40005];
int visit[40005];
int par[25][40005];
int dist[25][40005];
int lv[40005];
int n;
void dfs(int x, int parent, int level) {
	visit[x] = 1;
	par[0][x] = parent;
	lv[x] = level;
	for (int i = 0; i < edge[x].size(); i++) {
		if (visit[edge[x][i].first]) continue;
		dist[0][edge[x][i].first] = edge[x][i].second;
		dfs(edge[x][i].first, x, level + 1);
	}
}
void dp() {
	for (int i = 1; i <= 20; i++) {
		for (int j = 1; j <= n; j++) {
			par[i][j] = par[i - 1][par[i - 1][j]];
			dist[i][j] = dist[i - 1][j] + dist[i - 1][par[i - 1][j]];
		}
	}
}
int sum;
int lv_up(int x, int level) {
	for (int i = 20; i >= 0; i--) {
		if (level&(1 << i)) {
			int son = x;
			x = par[i][x];
			sum += dist[i][son];
		}
	}
	return x;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int i, j;//for문변수-->가끔식 long으로
	cin >> n;
	for (i = 1; i < n; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		edge[a].push_back({ b,c });
		edge[b].push_back({ a,c });
	}
	dfs(1, 0, 0);
	dp();
	int m; cin >> m;
	for (i = 0; i < m; i++) {
		sum = 0;
		int a, b; cin >> a >> b;
		a = lv_up(a, max(0, lv[a] - lv[b]));
		b = lv_up(b, max(0, lv[b] - lv[a]));
		if (a == b) {
			cout << sum << "\n";
		}
		else {
			for (j = 20; j >= 0; j--) {
				if (par[j][a] != par[j][b]) {
					int son_a = a, son_b = b;
					a = par[j][a]; b = par[j][b];
					sum += dist[j][son_a];
					sum += dist[j][son_b];
				}
			}
			int son_a = a, son_b = b;
			a = par[0][a]; b = par[0][b];
			sum += dist[0][son_a];
			sum += dist[0][son_b];
			cout << sum << "\n";
		}

	}
	//for(i=0;i<n;i++) {}
	//for(i=0;i<n;i++) { for(j=0;j<n;j++) { } }

	return 0;
}