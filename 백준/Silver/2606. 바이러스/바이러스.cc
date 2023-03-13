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
#define N 105
#define ll long long
#define endl "\n"
#define MID(a,b) (a+b)/2

using namespace std;

vector<int> edge[N];
int visit[N];
void bfs(int st) {
	queue<int> q;
	q.push(1);
	visit[1] = 1;
	int cnt = 0;
	while (q.size()) {
		int now = q.front();
		q.pop();
		for (auto it : edge[now]) {
			if (visit[it] == 0) {
				visit[it] = 1;
				q.push(it);
				cnt++;
			}
		}
	}
	cout << cnt;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, j; //for문 변수 -> longlong필요한지 확인
	int n, m; cin >> n >> m;
	for (i = 1; i <= m; i++) {
		int a, b; cin >> a >> b;
		edge[a].push_back(b);
		edge[b].push_back(a);
	}
	bfs(1);
	return 0;
}