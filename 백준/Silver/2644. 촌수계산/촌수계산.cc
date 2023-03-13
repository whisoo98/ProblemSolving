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
vector<int>v[105];
int n,m;
int visit[105];
void dfs(int x) {
	for (int i = 0; i < v[x].size(); i++) {
		if (!visit[v[x][i]]) {
			visit[v[x][i]] = visit[x] + 1;
			dfs(v[x][i]);
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int i, j;//for문변수-->가끔식 long으로
	cin >> n;
	int start, end;
	cin >> start >> end >> m;
	for (i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	visit[start] = 0;
	dfs(start);
	if (!visit[end]) cout << "-1";
	else cout << visit[end];
	return 0;
}