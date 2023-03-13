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
#include <cmath>
#include <sstream>


using namespace std;

/*struct type_name {

}srt;*/

//vector <type> vec;
//stack <type> stk;
//queue <type> q;
//string str;
//map <key_type,value_type> m;
int visit[100005];
int chk[100005];
vector<int> edge[100005];
int start, ed, cnt,flag;
int Total;
void dfs2(int now) {
	visit[now] = 2; cnt++; chk[now] = 1;
	if (visit[edge[now][0]] != 2) dfs2(edge[now][0]);
}
void dfs(int st, int now) {
	if (chk[now]) {
		return;
	}
	visit[now] = 1;
	ed = edge[now][0];
	for (int i = 0; i < 1; i++) {
		if (visit[edge[now][i]] == 0) {
			//ed = edge[now][i];
			dfs(st, edge[now][i]);
		}
	}
	if (now == ed) {
		dfs2(now);
		Total -= cnt;
	}

}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int i, j;//for문변수-->가끔식 long으로
	int T; cin >> T;
	while (T--) {
		
		int n; cin >> n;
		Total = n;
		for (i = 1; i <= n; i++) {
			int a; cin >> a;
			edge[i].push_back(a);
		}
		for (i = 1; i <= n; i++) {
			start = i; cnt = 0; 
			dfs(i, i);
			
		}
		cout << Total << "\n";
		for (i = 1; i <= n; i++) {
			visit[i] = 0;
			edge[i].clear();
			chk[i] = 0;
		}
	}

	//for(i=0;i<n;i++) {}
	//for(i=0;i<n;i++) { for(j=0;j<n;j++) { } }

	return 0;
}