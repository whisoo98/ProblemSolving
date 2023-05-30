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
#define N 1'000'005
#define ll long long
#define endl "\n"
#define MID(a,b) (a+b)/2
#define LEAF 0
using namespace std;

vector<int> edge[N];
int ans;
int visit[N];
int dfs(int node) {
	int have_childs = 0;
	int child_color=1;
	int colored = 0;
	for (auto it : edge[node]) {
		int temp = 0;
		if (!visit[it]) {
			have_childs = 1;
			visit[it] = 1;
			temp = dfs(it);
			child_color *= temp;
		}
	}
	if (have_childs == 0) return LEAF;

	if (child_color == 0) {
		colored = 1;
	}
	ans += colored;
	return colored;
}

void Solution(int n) {
	/*visit[0] = 1;
	edge[0].push_back(1);
	dfs(0);*/
	visit[1] = 1;
	dfs(1);
	cout << ans << endl;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, j; //for문 변수 -> longlong필요한지 확인
	int n; cin >> n;
	for (int i = 1; i < n; i++) {
		int a, b; cin >> a >> b;
		edge[a].push_back(b);
		edge[b].push_back(a);
	}
	Solution(n);
	return 0;
}