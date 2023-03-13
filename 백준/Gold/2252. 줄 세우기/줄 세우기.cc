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

/*struct type_name {}srt;*/
//vector <type> vec;
//stack <type> stk;
//queue <type> q;
//string str;
//map <key_type,value_type> m;

int V, E;
vector<int>edge[33000];
stack<int> ans;
int visit[33000];
void dfs(int x) {
	visit[x] = 1;
	for (int i = 0; i < edge[x].size(); i++) {
		if (!visit[edge[x][i]])
			dfs(edge[x][i]);
	}
	ans.push(x);

}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int i, j;//for문변수-->가끔식 long으로
	cin >> V >> E;
	for (i = 1; i <= E; i++) {
		int a, b;
		cin >> a >> b;
		edge[a].push_back(b);
	}
	for (i = 1; i <= V; i++) {
		if (!visit[i]) dfs(i);
	}
	while (!ans.empty()) {
		printf("%d ", ans.top());
		ans.pop();
	}
	return 0;
}