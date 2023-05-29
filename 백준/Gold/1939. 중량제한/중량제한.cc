#include <iostream>
#include <algorithm>
#include <functional>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <string>
#include <queue>
#include <stack>
#include <map>
#include <vector>
#include <set>
#include <sstream>
#include <ctime>
#include <climits>
#include <tuple>
#define N 10'005
#define ll long long
#define endl "\n"
#define MID(a,b) (a+b)/2

using namespace std;

vector<pair<int, int>> edge[N];
priority_queue<pair<int, int>> pq;
//vector<tuple<int, int, int>> edges;
map<pair<int, int>, int> edges;
map<int, int> mp;
int visit[N];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, j; //for문 변수 -> longlong필요한지 확인
	int V, E; cin >> V >> E;
	for (int i = 1; i <= E; i++) {
		int a, b, c; cin >> a >> b >> c;
		//edges.push_back({ a,b,c });
		if (edges.count({ a,b })) {
			edges[{a, b}] = max(edges[{a, b}], c);
		}
		else {
			edges[{a, b}] = c;
		}
		/*edge[a].push_back({ c,b });
		edge[b].push_back({ c,a });*/
	}
	/*edges.erase(unique(edges.begin(), edges.end()), edges.end());
	for (auto it : edges) {
		int a, b, c;
		a = get<0>(it);
		b = get<1>(it);
		c = get<2>(it);
		edge[a].push_back({ c,b });
		edge[b].push_back({ c,a });
	}*/
	for (auto it : edges) {
		int a = it.first.first;
		int b = it.first.second;
		int c = it.second;
		edge[a].push_back({ c,b });
		edge[b].push_back({ c,a });
	}
	int src, dst; cin >> src >> dst;
	pq.push({ INT_MAX,src });
	visit[src] = INT_MAX;
	while (pq.size()) {
		int weight = pq.top().first;
		int now = pq.top().second;
		pq.pop();
		for (auto it : edge[now]) {
			int cost = it.first;
			int next = it.second;
			if (visit[next] < min(weight, cost)) {
				visit[next] = min(weight, cost);
				pq.push({ visit[next],next });
			}
		}
	}
	cout << visit[dst] << endl;
	return 0;
}