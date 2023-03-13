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
#define INF 987654321
#define ll long long
#define endl "\n"
#define MID(a,b) (a+b)/2

using namespace std;

vector<pair<int,int>> edge[N];
int arr[N][N];
queue<pair<int, int>> query;
stack<pair<int, int>> stk;

int visit[N];
int dist;
void dfs(int st, int n) {
	visit[n] = 1;
	arr[st][n] = arr[n][st] = dist;
	for (auto it : edge[n]) {
		int next = it.first;
		int cost = it.second;
		if (visit[next] == 0) {
			dist += cost;
			dfs(st, next);
			dist -= cost;
		}
	}
}

void Solution(int n, int m) {
	for (int i = 0; i < m; i++) {
		dist = 0;
		for (int i = 1; i <= n; i++) {
			visit[i] = 0;
		}
		int a = query.front().first;
		int b = query.front().second;
		query.pop();
		if (arr[a][b] != INF) cout << arr[a][b] << endl;
		else {
			dfs(a,a);
			cout << arr[a][b] << endl;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, j; //for문 변수 -> longlong필요한지 확인
	int n, m; cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			arr[i][j] = INF;
		}
		arr[i][i] = 0;
	}
	for (int i = 0; i < n-1; i++) {
		int a, b, c; cin >> a >> b >> c;
		edge[a].push_back({ b,c });
		edge[b].push_back({ a,c });
		arr[a][b] = c;
		arr[b][a] = c;
	}
	for (int i = 0; i < m; i++) {
		int a, b; cin >> a >> b;
		query.push({ a,b });
	}
	Solution(n, m);
	return 0;
}