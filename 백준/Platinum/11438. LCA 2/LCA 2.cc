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
vector<int>edge[100005];
int visit[100005];
int parent[35][100005];
int lv[100005];
int n;
void dfs(int x, int par, int level) {
	visit[x] = 1;
	parent[0][x] = par;
	lv[x] = level;
	for (int i = 0; i < edge[x].size(); i++) {
		if (visit[edge[x][i]]) continue;
		dfs(edge[x][i], x, level + 1);
	}
}

void dp() {
	for (int i = 1; i <= 30; i++) {
		for (int j = 1; j <= n; j++) {
			parent[i][j] = parent[i - 1][parent[i - 1][j]];
		}
	}
}
int lv_up(int x, int level) {
	for (int i = 30; i >= 0; i--) {
		if (level&(1 << i)) x = parent[i][x];
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
		int a, b; cin >> a >> b;
		edge[a].push_back(b);
		edge[b].push_back(a);
	}
	dfs(1,1,0);
	dp();
	int m; cin >> m;
	for (j = 0; j < m; j++) {
		int a, b; cin >> a >> b;
		a = lv_up(a, max(0, lv[a] - lv[b]));
		b = lv_up(b, max(0, lv[b] - lv[a]));
		if (a == b) {
			cout << a << "\n";
			continue;
		}
		else {
			for (i = 30; i >= 0; i--) {
				if (parent[i][a] != parent[i][b]) {
					a = parent[i][a];
					b = parent[i][b];
				}
			}
			cout << parent[0][a] << "\n";
		}
	}
	//for(i=0;i<n;i++) { for(j=0;j<n;j++) { } }

	return 0;
}