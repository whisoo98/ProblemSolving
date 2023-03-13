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

using namespace std;

ll arr[N];
ll tree[4 * N];

ll init(int start, int end, int node) {
	if (start == end) return tree[node] = arr[start];
	int mid = MID(start, end);
	return tree[node] = init(start, mid, node * 2) + init(mid + 1, end, node * 2 + 1);
}

ll sum(int start, int end, int node, int left, int right) {
	if (right<start || left>end) return 0;
	if (left <= start && end <= right)return tree[node];
	int mid = MID(start, end);
	return sum(start, mid, node * 2, left, right) + sum(mid + 1, end, node * 2 + 1, left, right);
}

void update(int start, int end, int idx, int node, ll diff) {
	if (idx<start || idx>end) return;
	if (start == end) {
		tree[node] = diff;
		return;
	}
	int mid = MID(start, end);
	update(start, mid, idx, node * 2, diff);
	update(mid + 1, end, idx, node * 2 + 1, diff);
	tree[node] = tree[node * 2] + tree[node * 2 + 1];
}



int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, j; //for문 변수 -> longlong필요한지 확인
	int n, m; cin >> n >> m;
	for (i = 1; i <= m; i++) {
		int cmd; cin >> cmd;
		int a, b; cin >> a >> b;
		if (cmd) {
			update(1, n, a, 1, (ll)b);
		}
		else {
			int ta = min(a, b);
			int tb = max(a, b);
			a = ta;
			b = tb;
			cout << sum(1, n, 1, a, b) << endl;
		}
	}

	return 0;
}