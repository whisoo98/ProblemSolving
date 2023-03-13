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

int parent[200005];

int Find(int x) {
	if (parent[x] == x) return x;
	return parent[x] = Find(parent[x]);
}
void Union(int x, int y) {
	if (Find(x) != Find(y))
		parent[Find(x)] = Find(y);
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, j; //for문 변수 -> longlong필요한지 확인
	int n, m;
	while (1) {
		cin >> n >> m;
		if (!(n*m)) break;
		
		for (i = 0; i < n; i++) {
			parent[i] = i;
		}
		int save = 0;
		priority_queue<tuple<int, int, int>> pq;
		for (i = 0; i < m; i++) {
			int a, b, c; cin >> a >> b >> c;
			save += c;
			pq.push({ -c,a,b });
		}
		int cnt = 1;
		int sum = 0;
		while (cnt < n) {
			int weight = -get<0>(pq.top());
			int a = get<1>(pq.top());
			int b = get<2>(pq.top());
			pq.pop();
			if (Find(a) != Find(b)) {
				Union(a, b);
				cnt++;
				sum += weight;
			}
		}
		cout << save-sum << "\n";
		for (i = 0; i < n; i++) parent[i] = 0;
	}

	return 0;
}