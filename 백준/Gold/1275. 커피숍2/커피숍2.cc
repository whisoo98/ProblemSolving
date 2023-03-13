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
#define ll long long
#define N 100005
using namespace std;

ll arr[N];
ll tree[4 * N];

ll init(int start, int end, int node) {
	if (start == end) return tree[node] = arr[start];
	int mid = (start + end) / 2;
	return tree[node] = init(start, mid, node * 2) + init(mid + 1, end, node * 2 + 1);
}

ll sum(int start, int end, int node, int left, int right) {
	if (left > end || right < start) return 0;
	int mid = (start + end) / 2;
	if (left <= start && end <= right) return tree[node];
	return sum(start, mid, node * 2, left, right) + sum(mid + 1, end, node * 2 + 1, left, right);
}

void update(int start, int end, int node, int idx, ll diff) {
	if (idx < start || idx > end) return;
	tree[node] += diff;
	if (start == end) return;
	int mid = (start + end) / 2;
	update(start, mid, node * 2, idx, diff);
	update(mid + 1, end, node * 2 + 1, idx, diff);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, j; //for문 변수 -> longlong필요한지 확인
	int n, q; cin >> n >> q;
	for (i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	init(1, n, 1);
	for (i = 1; i <= q; i++) {
		int a, b, c; ll d;
		cin >> a >> b >> c >> d;
		int m = min(a, b);
		int M = max(a, b);
		cout << sum(1, n, 1, m, M)<<"\n";
		ll diff = d - arr[c];
		arr[c] = d;
		update(1, n, 1, c, diff);
	}

	return 0;
}