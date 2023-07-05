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

int subtree[N];
int visit[N];
vector<int> edge[N];



int traverse(int n, int root, int node) {
	int sum = 1;
	for (auto child : edge[node]) {
		if (visit[child] == 0) {
			visit[child] = 1;
			sum += traverse(n, root, child);
		}
	}
	return subtree[node]=sum;
}

void Solution(int n, int root, int q) {
	visit[root] = 1;
	traverse(n, root, root);
	for (int i = 0; i < q; i++) {
		int u; cin >> u;
		cout << subtree[u] << endl;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, j; //for문 변수 -> longlong필요한지 확인
	int n, root, q; cin >> n >> root >> q;
	for (int i = 0; i < n-1; i++) {
		int u, v; cin >> u >> v;
		edge[u].push_back(v);
		edge[v].push_back(u);
	}
	Solution(n, root, q);

	return 0;
}