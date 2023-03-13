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
int indegree[33000];
vector<int> edge[33000];

priority_queue<int,vector<int>,greater<int>> pq;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);		
	cout.tie(NULL);
	int i, j;//for문변수-->가끔식 long으로
	int n, m; cin >> n >> m;
	for (i = 0; i < m; i++) {
		int a, b; cin >> a >> b;
		edge[a].push_back(b);
		indegree[b]++;
	}
	for (i = 1; i <= n; i++) {
		if (!indegree[i]) pq.push(i);
	}
	while (!pq.empty()) {
		int st = pq.top(); cout << st << " "; pq.pop();
		sort(edge[st].begin(), edge[st].end());
		for (i = 0; i < edge[st].size(); i++) {
			indegree[edge[st][i]]--;
			if (!indegree[edge[st][i]]) pq.push(edge[st][i]);
		}
	}

		
	
	//by dfs
	//for(i=0;i<n;i++) {}
	//for(i=0;i<n;i++) { for(j=0;j<n;j++) { } }

	return 0;
}