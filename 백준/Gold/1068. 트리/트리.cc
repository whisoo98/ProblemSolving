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


int V, E;
vector<int>edge[55];
int visit[55];
int parent[55];
int cnt;
void dfs(int now) {

	for (int i = 0; i < edge[now].size(); i++) {
		if (!visit[edge[now][i]]) {
			visit[edge[now][i]] = 1;
			dfs(edge[now][i]);
		}
	}
	if (edge[now].size() == 0) cnt++;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int i, j;//for문변수-->가끔식 long으로
	
	int n; cin >> n;
	int root;
	for (i = 0; i < n; i++) {
		int par; cin >> par;
		parent[i] = par;
		if (par != -1) {
			edge[par].push_back(i);
		}
		else{
			root = i;
		}
	}
	int del; cin >> del;
	if (parent[del] == -1) {
		cout << 0;
	}
	else {
		int size = edge[parent[del]].size();
		for (i = 0; i < size; i++) {
			if (edge[parent[del]][i] == del) {
				edge[parent[del]].erase(edge[parent[del]].begin() + i);
			}
		}
		dfs(root);
		cout << cnt;
	}

	//for(i=0;i<n;i++) {}
	//for(i=0;i<n;i++) { for(j=0;j<n;j++) { } }

	return 0;
}