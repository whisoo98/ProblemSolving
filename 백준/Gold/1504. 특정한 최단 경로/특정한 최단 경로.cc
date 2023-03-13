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
int V, E;
vector<pair<long long, long long>>edge[805];
long long visit0[805];
long long visit1[805];
long long visit2[805];

priority_queue<pair<long long, long long>> q;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int i, j;//for문변수-->가끔식 long으로
	scanf("%d %d", &V, &E);
	for (i = 0; i <= V; i++) {
		visit0[i] = 987654321;
		visit1[i] = 987654321;
		visit2[i] = 987654321;
	}
	for (i = 0; i < E; i++) {
		int a, b, c; scanf("%d %d %d", &a, &b, &c);
		edge[a].push_back({ c,b });
		edge[b].push_back({ c,a });
	}
	int route1, route2; scanf("%d %d", &route1, &route2);


	visit1[route1] = 0;
	q.push({ 0,route1 });
	while (!q.empty()) {
		int now = q.top().second;
		int distance = -q.top().first;
		q.pop();
		for (auto iter = edge[now].begin(); iter != edge[now].end(); iter++) {
			if (visit1[iter->second] > iter->first + distance) {
				visit1[iter->second] = iter->first + distance;
				q.push({ -visit1[iter->second],iter->second });
			}
		}
	}
	visit2[route2] = 0;
	q.push({ 0,route2 });
	while (!q.empty()) {
		int now = q.top().second;
		int distance = -q.top().first;
		q.pop();
		for (auto iter = edge[now].begin(); iter != edge[now].end(); iter++) {
			if (visit2[iter->second] > iter->first + distance) {
				visit2[iter->second] = iter->first + distance;
				q.push({ -visit2[iter->second],iter->second });
			}
		}
	}
	visit0[1] = 0;
	q.push({ 0,1 });
	while (!q.empty()) {
		int now = q.top().second;
		int distance = -q.top().first;
		q.pop();
		for (auto iter = edge[now].begin(); iter != edge[now].end(); iter++) {
			if (visit0[iter->second] > iter->first + distance) {
				visit0[iter->second] = iter->first + distance;
				q.push({ -visit0[iter->second],iter->second });
			}
		}
	}

	if (min(visit0[route1] + visit1[route2] + visit2[V], visit0[route2] + visit2[route1] + visit1[V]) >= 987654321) printf("-1");
	else printf("%lld", min(visit0[route1] + visit1[route2] + visit2[V], visit0[route2] + visit2[route1] + visit1[V]));

	return 0;
}