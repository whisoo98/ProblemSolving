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
#define N 100'005
#define ll long long
#define endl "\n"
#define MID(a,b) (a+b)/2

using namespace std;

vector<int> edge[N];
int visit[N];

void dfs(int now) {
	for (auto it : edge[now]) {
		if (!visit[it]) {
			visit[it] = now;
			dfs(it);
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
	for (i = 1; i < n; i++) {
		int a,b; cin >> a>>b;
		edge[a].push_back(b);
		edge[b].push_back(a);

	}
	dfs(1);

	visit[1] = 1;
	for (i = 2; i <= n; i++) {
		cout << visit[i] << endl;
	}
	return 0;
}