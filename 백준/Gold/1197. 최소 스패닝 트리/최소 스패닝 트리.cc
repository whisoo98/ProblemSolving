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
#define N 10005
#define ll long long
#define endl "\n"
#define MID(a,b) (a+b)/2

using namespace std;

priority_queue<tuple<int, int, int>>pq;
pair<int, int>p;


int parent[N];
int W;

int Find(int x) {
	if (parent[x] == x) return x;
	return parent[x] = Find(parent[x]);
}

void Union(int x,int y) {
	x = Find(x);
	y = Find(y);
	if (x != y) {
		parent[x] = y;
		//height,rank
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, j; //for문 변수 -> longlong필요한지 확인
	int n, m; cin >> n >> m;
	for (i = 1; i <= n; i++) {
		parent[i] = i;
	}
	for (i = 1; i <= m; i++) {
		int a, b, c; cin >> a >> b >> c;
		pq.push({ -c,a,b });
	}
	while (!pq.empty()) {
		int cost = -get<0>(pq.top());
		int a = get<1>(pq.top());
		int b = get<2>(pq.top());
		pq.pop();
		a = Find(a);
		b = Find(b);
		if (a != b) {
			Union(a, b);
			W += cost;
		}
	}
	cout << W;
	return 0;
}