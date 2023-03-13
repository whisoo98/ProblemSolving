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
int V, E;
vector<pair<int, int>> edge[20005];
priority_queue<pair<int, int>> q;
int visit[20005];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int i, j;//for문변수-->가끔식 long으로
	scanf("%d %d", &V, &E);
	for (i = 1; i <= V; i++) visit[i] = INT_MAX;
	int start; scanf("%d", &start);
	for (i = 1; i <= E; i++) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		edge[a].push_back({ c,b });

	}
	visit[start] = 0;
	q.push({ 0, start });
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
	for (i = 1; i <= V; i++) {
		if (visit[i] == INT_MAX) {
			printf("INF\n");
			continue;
		}
		printf("%d\n", visit[i]);
	}
	return 0;
}