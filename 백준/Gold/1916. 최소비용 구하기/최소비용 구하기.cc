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
#define N 1005
#define INF (INT_MAX-987654321)
#define ll long long
#define endl "\n"
#define MID(a,b) (a+b)/2

using namespace std;
int visit[N];
vector<pair<int, int>> edge[N];

void dijk(int st,int ed) {
	priority_queue<pair< int, int>> pq;
	pq.push({ -0,st });
	visit[st] = 0;
	while (pq.size()) {
		int cost = -pq.top().first;
		int now = pq.top().second;
		pq.pop();
		if (now == ed) return;
		for (auto it : edge[now]) {
			if (visit[it.second] >  cost+ it.first) {
				visit[it.second] = cost + it.first;
				pq.push({ -visit[it.second],it.second });
			}
		}
	}

}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, j; //for문 변수 -> longlong필요한지 확인
	int n; cin >> n;
	int m; cin >> m;
	for (int i = 1; i <= n; i++) visit[i] = INF;
	for (int i = 1; i <= m; i++) {
		int a, b, c; cin >> a >> b >> c;
		edge[a].push_back({ c,b });
	}
	int st, ed; cin >> st >> ed;
	dijk(st,ed);
	cout << visit[ed];
	return 0;
}