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
#define ll long long
#define endl "\n"
#define MID(a,b) (a+b)/2

using namespace std;

vector<int> edge[N];
int visitD[N];
int visitB[N];
void dfs(int n) {
	visitD[n] = 1;
	cout << n << " ";
	for (auto it : edge[n]) {
		if (visitD[it] == 0) {
			dfs(it);
		}
	}
}

void bfs(int n) {
	queue<int> q;
	visitB[n] = 1;
	q.push(n);
	while (q.size()) {
		int now = q.front();
		cout << now << " ";
		q.pop();
		for (auto it : edge[now]) {
			if (visitB[it] == 0) {
				q.push(it);
				visitB[it] = 1;
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
	int n, m, st; cin >> n >> m >> st;
	for (int i = 0; i < m; i++) {
		int a, b; cin >> a >> b;
		edge[a].push_back(b);
		edge[b].push_back(a);
	}
	for (int i = 1; i <= n; i++) {
		sort(edge[i].begin(), edge[i].end());
	}
	dfs(st);
	cout << endl;
	bfs(st);
	cout << endl;

	return 0;
}