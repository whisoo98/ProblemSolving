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
vector<int> edge[10005];
vector<int>answer;
int visit[10005];
int M = -987654321;
queue<int>q;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int i, j;//for문변수-->가끔식 long으로
	int n, m; cin >> n >> m;
	for (i = 0; i < m; i++) {
		int a, b; cin >> a >> b;
		edge[b].push_back(a);
	}
	for (i = 1; i <= n; i++) {
		int cnt = 0;
		q.push(i);
		visit[i] = i;
		while (!q.empty()) {
			cnt++;
			int now = q.front(); q.pop();
			int size = edge[now].size();
			for (j = 0; j < size; j++) {
				if (visit[edge[now][j]] != i) {
					visit[edge[now][j]] = i;
					q.push(edge[now][j]);
				}
			}
		}
		
		if (cnt >= M) {
			if (cnt > M) {
				answer.clear();
				answer.push_back(i);
				M = cnt;
			}
			else {
				answer.push_back(i);
			}
		}
	}
	sort(answer.begin(), answer.end());
	int size = answer.size();
	for (i = 0; i < size; i++) {
		cout << answer[i] << " ";
	}
	//for(i=0;i<n;i++) {}
	//for(i=0;i<n;i++) { for(j=0;j<n;j++) { } }

	return 0;
}