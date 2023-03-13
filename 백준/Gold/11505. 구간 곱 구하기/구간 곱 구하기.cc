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
#define N 1000005
#define M 1000000007
using namespace std;

long long arr[N];
long long tree[4 * N];

long long init(int start, int end, int node) {
	if (start == end) return tree[node] = arr[start] % M;
	int mid = (start + end) / 2;
	return tree[node] = (init(start, mid, node * 2) % M * init(mid + 1, end, node * 2 + 1) % M) % M;
}

long long query(long long start, long long end, int node, long long left, long long right) {
	if (right < start || left > end) return 1;
	if (left <= start && end <= right) return tree[node] % M;
	long long mid = (start + end) / 2;
	return ((query(start, mid, node * 2, left, right) % M) 
		* (query(mid + 1, end, node * 2 + 1, left, right) % M)) % M;
}

void update(long long start, long long end, int node, long long idx, long long before, long long after) {
	if (idx < start || end < idx) return;
	if (start == end) {
		tree[node] = arr[start] % M;
		return;
	}
	long long mid = (start + end) / 2;
	update(start, mid, node * 2, idx, before, after);
	update(mid + 1, end, node * 2 + 1, idx, before, after);
	tree[node] = (tree[node * 2] % M * tree[node * 2 + 1] % M) % M;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, j; //for문 변수 -> longlong필요한지 확인
	int n, m, k; cin >> n >> m >> k;
	for (i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	init(1, n, 1);
	for (i = 1; i <= m + k; i++) {
		long long a, b, c; cin >> a >> b >> c;
		if (a == 1) {
			//int diff = c - arr[b];
			arr[b] = c;
			update(1, n, 1, b, arr[b], c);
		}
		else if (a == 2) {
			cout << query(1, n, 1, b, c) << "\n";
		}
	}

	return 0;
}