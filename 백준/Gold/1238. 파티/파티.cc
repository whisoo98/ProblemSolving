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
#include<climits>

using namespace std;

/*struct type_name {

}srt;*/

//vector <type> vec;
//stack <type> stk;
//queue <type> q;
//string str;
//map <key_type,value_type> m;
vector<pair<int,int>> edge[1005];
int V, E;
priority_queue<pair<int, int>> q;
int visit[1005];
int sum[1005];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int i, j;//for문변수-->가끔식 long으로
	int setup;
	scanf("%d %d %d", &V, &E, &setup);
	for (i = 0; i < E; i++) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		edge[a].push_back({ c,b });
	}

	for (i = 1; i <= V; i++) {
		for (j = 1; j <= V; j++) visit[j] = INT_MAX;
		if (i == setup) {
			visit[i] = 0;
			q.push({ visit[i],i });
			while (!q.empty()) {
				int now = q.top().second;
				int distance = -q.top().first;
				q.pop();
				for (auto it = edge[now].begin(); it != edge[now].end(); it++) {
					if (visit[it->second] > distance + it->first) {
						visit[it->second] = distance + it->first;
						q.push({ -visit[it->second],it->second });
					}
				}
			}
			for (j = 1; j <= V; j++) sum[j] += visit[j];
		}

		else {
			visit[i] = 0;
			q.push({ visit[i],i });
			while (!q.empty()) {
				int now = q.top().second;
				int distance = -q.top().first;
				q.pop();
				for (auto it = edge[now].begin(); it != edge[now].end(); it++) {
					if (visit[it->second] > distance + it->first) {
						visit[it->second] = distance + it->first;
						q.push({ -visit[it->second],it->second });
					}
				}
			}
			sum[i] += visit[setup];
		}
	}


	sort(sum + 1, sum + 1 + V, greater<int>());
	//for (i = 1; i <= V; i++) printf("%d\n", sum[i]);
	printf("%d", sum[1]);
	return 0;
}
