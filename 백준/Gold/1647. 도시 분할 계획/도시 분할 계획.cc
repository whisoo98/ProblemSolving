#include <iostream>
#include <algorithm>
#include <functional>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <string>
#include <queue>
#include <stack>
#include <map>
#include <vector>
#include <set>
#include <sstream>

using namespace std;


priority_queue<tuple<int, int, int>> pq;
int parent[100005];
int Find(int x) {
	if (parent[x] == x)return x;
	return parent[x] = Find(parent[x]);
}
void Union(int x, int y) {
	if (Find(x) != Find(y)) {
		parent[Find(x)] = Find(y);
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, j; //for문 변수 -> longlong필요한지 확인
	int n, m; cin >> n >> m;
	for (i = 0; i < m; i++) {
		int a, b, c; cin >> a >> b >> c;
		pq.push({ -c,a,b });
	}
	for (i = 1; i <= n; i++) {
		parent[i] = i;
	}
	int M = -1;
	int sum = 0;
	int cnt = 1;
	while (cnt < n) {
		int weight = -get<0>(pq.top());
		int a = get<1>(pq.top()),b = get<2>(pq.top());
		pq.pop();
		if (Find(a) != Find(b)) {
			Union(a, b);
			cnt++;
			sum += weight;
			M = max(M, weight);
		}
	}
	cout << sum - M;
	return 0;
}