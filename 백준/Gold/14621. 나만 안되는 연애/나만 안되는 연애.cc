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

int parent[N];
int sex[N];
priority_queue <tuple<int, int, int>> pq;
int sum;

int Find(int x) {
	if (parent[x] == x) return x;
	return parent[x] = Find(parent[x]);
}

void Union(int x, int y) {
	
	if (x != y) parent[x] = y;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, j; //for문 변수 -> longlong필요한지 확인
	int n, m; cin >> n >> m;
	for (i = 1; i <= n; i++) {
		char a; cin >> a;
		sex[i] = (int)a;
		parent[i] = i;
	}
	for (i = 1; i <= m; i++) {
		int a, b, c; cin >> a >> b >> c;
		pq.push({ -c,a,b });
	}
	while (!pq.empty()) {
		int cost = -get<0>(pq.top());
		int st = get<1>(pq.top());
		int ed = get<2>(pq.top());
		pq.pop();
		if (sex[st] == sex[ed]) {
			continue;
		}
		else {
			st = Find(st);
			ed = Find(ed);
			if (st != ed) {
				Union(st, ed);
				sum += cost;
			}
		}
	}
	int base = Find(1);
	int chk = 0;
	for (i = 2; i <= n; i++) {
		if (Find(i) != base) {
			chk++;
			break;
		}
	}
	if (chk) cout << -1;
	else cout << sum;
	return 0;
}