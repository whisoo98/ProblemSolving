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
#define N 55
#define int long long
#define endl "\n"
#define MID(a,b) (a+b)/2
#define INF 987654321
using namespace std;


int edge[N][N];
vector <tuple <int,int, int >> edges;
vector <int> NegEdge;
bool isNeg[N];
int vertex[N];
int dist[N];
void BellmanFord(int st, int ed, int n, int m) {
	dist[st] = vertex[st];
	int sz = edges.size();
	for (int i = 0; i <n; i++) {
		for (int j = 0; j < sz; j++) {
			int from = get<0>(edges[j]);
			int to = get<1>(edges[j]);
			int cost = get<2>(edges[j]);
			if (dist[from] == INF) continue;
			if (dist[to] > dist[from] + cost) {
				dist[to] = dist[from] + cost;
			}
		}
	}
}

int isNegativeCycle(int st, int ed, int n, int m) {
	int chk = 0;
	int sz = edges.size();

	for (int j = 0; j < sz; j++) {
		int from = get<0>(edges[j]);
		int to = get<1>(edges[j]);
		int cost = get<2>(edges[j]);
		if (dist[from] == INF) continue;
		if (dist[to] > dist[from] + cost) {
			dist[to] = dist[from] + cost;
			chk = 1;
			if (!isNeg[to]) {
				NegEdge.push_back(to);
				isNeg[to] = true;
			}
			if (!isNeg[from]) {
				NegEdge.push_back(from);
				isNeg[from] = true;
			}
			
		}
	}
	return chk;
}
bool visit[N];
void dfs(int now,int n) {
	visit[now] = true;
	//int st = NegEdge[0];
	for (int i = 0; i < n; i++) {
		if (edge[now][i] == INF) continue;
		if (visit[i] == false) {
			dfs(i, n);
		}
	}

}

void Solution(int st, int ed, int n, int m) {
	BellmanFord(st, ed, n, m);
	int NegCycle = isNegativeCycle(st, ed, n, m);
	if (dist[ed] == INF) {
		cout << "gg" << endl;
	}
	else {
		if (NegCycle) {
			int sz = NegEdge.size();
			for (int i = 0; i < sz;i++) {
				dfs(NegEdge[i], n);
			}
			if(visit[ed])
				cout << "Gee" << endl;
			else
				cout << -dist[ed] << endl;
		}
		else {
			cout << -dist[ed] << endl;
		}
	}
}

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, j; //for문 변수 -> longlong필요한지 확인
	int n; cin >> n;
	int st, ed; cin >> st >> ed;
	int m; cin >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			edge[i][j] = INF;
		}
		dist[i] = INF;
	}

	for (int i = 0; i < m; i++) {
		int a, b, c; cin >> a >> b >> c;
		/*if (edge[a][b] == INF) edge[a][b] = c;
		else edge[a][b] = min(edge[a][b], c);*/
		edge[a][b] = min(edge[a][b], c);
	}

	for (int i = 0; i < n; i++) {
		cin >> vertex[i];
		vertex[i] *= -1;
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if(edge[i][j] == INF) continue;
			else {
				edge[i][j] += vertex[j];
				edges.push_back({ i,j,edge[i][j] });
			}
		}
	}
	Solution(st, ed, n, m);
	return 0;
}