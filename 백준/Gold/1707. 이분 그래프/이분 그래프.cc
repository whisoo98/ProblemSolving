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

vector<int> edge[20005];
int visit[20005];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int i, j;//for문변수-->가끔식 long으로
	int T; cin >> T;
	while (T--) {
		int V, E; cin >> V >> E;
		if (V == 1) {
			cout << "YES\n";
			continue;
		}
		queue<pair<int,int>> q;
		for (i = 0; i < E; i++) {
			int a, b; cin >> a >> b;
			edge[a].push_back(b);
			edge[b].push_back(a);
		}
		//visit[1] = 1;
		//int chk = 1;
		int out = 0;
		for (j = 1; j <= V; j++) {
			if (out) break;
			if (visit[j] == 0) {
				q.push({ j,1 });
				visit[j] = 1;
				while (!q.empty()) {
					if (out) break;
					int now = q.front().first;
					int color = q.front().second;
					q.pop();

					int size = edge[now].size();

					for (i = 0; i < size; i++) {
						if (visit[edge[now][i]] == 0) {
							visit[edge[now][i]] = -color;
							q.push({ edge[now][i],-color });
						}
						else if (visit[edge[now][i]] == color) {
							out = 1;
							break;
						}
					}
				}
			}
		}
		if (out) {
			cout << "NO\n";
		//	break;
		}
		else {
			cout << "YES\n";
		//	break;
		}
		for (i = 1; i <= V; i++) {
			visit[i] = 0;
			edge[i].clear();
		}
	}

	//for(i=0;i<n;i++) {}
	//for(i=0;i<n;i++) { for(j=0;j<n;j++) { } }

	return 0;
}