#include <stdio.h>
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


using namespace std;

/*struct type_name {

}srt;*/

//vector <type> vec;
//stack <type> stk;
//queue <type> q;
//string str;
//map <key_type,value_type> m;
int V, E;
vector<int>edge[1005];
bool visit[1005];
void dfs(int x) {
	visit[x] = 1;
//	cout << x << " ";
	for (int i = 0; i < edge[x].size(); i++) {
		if (!visit[edge[x][i]]) dfs(edge[x][i]);
	}
}
int cnt;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int i, j;//for문변수-->가끔식 long으로
	cin >> V >> E;
	for (i = 0; i < E; i++) {
		int a, b;
		cin >> a >> b;
		edge[a].push_back(b);
		edge[b].push_back(a);
	}
	for (i = 1; i <= V; i++) {
		if (!visit[i]) {
			cnt++;
			dfs(i);
		}
	}
	cout << cnt;
	return 0;
}