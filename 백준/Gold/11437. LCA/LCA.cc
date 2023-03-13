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
int parent[100005];
int lv[100005];
void dfs(int x, int par, int level) {
	visit[x] = 1;
	parent[x] = par;
	lv[x] = level;
	for (int i = 0; i < edge[x].size(); i++) {
		if (visit[edge[x][i]]) continue;
		dfs(edge[x][i], x, level + 1);
	}
}
int lca(int x, int y) {
	if (lv[x] < lv[y]) swap(x, y);
	while (lv[x] != lv[y]) {
		x = parent[x];
	}
	while (x != y) {
		x = parent[x];
		y = parent[y];
	}
	return x;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int i, j;//for문변수-->가끔식 long으로
	int n; cin >> n;
	for (i = 1; i < n; i++) {
		int a, b; cin >> a >> b;
		edge[a].push_back(b);
		edge[b].push_back(a);
	}
	dfs(1,1,0);
	int m; cin >> m;
	for (i = 0; i < m; i++) {
		int a, b; cin >> a >> b;
		cout<<lca(a, b)<<"\n";
	}
	//for(i=0;i<n;i++) { for(j=0;j<n;j++) { } }

	return 0;
}