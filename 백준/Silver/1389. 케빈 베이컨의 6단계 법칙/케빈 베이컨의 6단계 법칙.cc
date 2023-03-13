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

int n, m;
vector<int> edge[105];
bool visit[105][105];
int cnt[105];

/*void dfs(int start,int now, int level) {
	visit[start][now] = 1;

	int size = edge[now].size();
	for (int i = 0; i < size; i++) {
		if (!visit[now][edge[now][i]]) {
			visit[now][edge[now][i]] = 1;
			cnt[start] += level;
			dfs(start, edge[now][i],level+1);
		}
	}
}*/
void bfs(int start, int level) {
	queue<pair<int,int>> q;
	q.push({ start,level });
	visit[start][start] = 1;
	while (!q.empty()) {
		
		int now = q.front().first, count = q.front().second; 
		q.pop();
		cnt[start] += count;
		int size = edge[now].size();
		for (int i = 0; i < size; i++) {
			if (!visit[start][edge[now][i]]) {
				q.push({ edge[now][i],count + 1 });
				visit[start][edge[now][i]] = 1;
			}
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int i, j;//for문변수-->가끔식 long으로
	cin >> n >> m;
	for (i = 0; i < m; i++) {
		int a, b; cin >> a >> b;
		edge[a].push_back(b);
		edge[b].push_back(a);
	}
	for (i = 1; i <= n; i++) {
	//	dfs(i,i,1);
		bfs(i, 0);
	}


	cout << min_element(cnt + 1, cnt + 1 + n) - cnt;
	
	//for(i=0;i<n;i++) {}
	//for(i=0;i<n;i++) { for(j=0;j<n;j++) { } }

	return 0;
}