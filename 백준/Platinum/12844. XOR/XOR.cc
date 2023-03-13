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
#define N 500005
#define ll long long
#define MID(a,b) (a+b)/2

using namespace std;

long long arr[N];
long long tree[4 * N];
long long lazy[4 * N];

long long init(int start, int end, int node) {
	if (start == end) return tree[node] = arr[start];
	int mid = (start + end) / 2;
	return tree[node] = init(start, mid, node * 2) ^ init(mid + 1, end, node * 2 + 1);
}

long long sum(int start, int end, int node, int left, int right) {
	if (lazy[node] != 0) {
		if ((end - start + 1) % 2) {
			tree[node] ^= lazy[node];
		}
		if (start != end) {
			lazy[node * 2] ^= lazy[node];
			lazy[node * 2 + 1] ^= lazy[node];
		}
		lazy[node] = 0;
	}
	if (left > end || right < start) return 0;
	if (left <= start && end <= right) return tree[node];
	int mid = (start + end) / 2;
	return sum(start, mid, node * 2, left, right) ^ sum(mid + 1, end, node * 2 + 1, left, right);
}

void update(int start, int end, int node, int index, long long diff) {
	if (index < start || index > end) return;
	tree[node] += diff;
	if (start == end) return;
	int mid = (start + end) / 2;
	update(start, mid, node * 2, index, diff);
	update(mid + 1, end, node * 2 + 1, index, diff);
}

void update_range(int start, int end, int node, int left, int right, long long diff) {
	if (lazy[node] != 0) {
		if ((end - start + 1) % 2) {
			tree[node] ^= lazy[node];
		}
		if (start != end) {
			lazy[node * 2] ^= lazy[node];
			lazy[node * 2 + 1] ^= lazy[node];
		}
		lazy[node] = 0;
	}

	if (right < start || end < left) return;

	if (left <= start && end <= right) {
		if ((end - start + 1) % 2) {
			tree[node] ^= diff;	
		}
		if (start != end) {
			lazy[node * 2] ^= diff;
			lazy[node * 2 + 1] ^= diff;
		}
		return;
	}

	int mid = (start + end) / 2;
	update_range(start, mid, node * 2, left, right, diff);
	update_range(mid + 1, end, node * 2 + 1, left, right, diff);

	tree[node] = tree[node * 2] ^ tree[node * 2 + 1];
}



int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, j; //for문 변수 -> longlong필요한지 확인
	int n; cin >> n;
	for (i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	init(1, n, 1);
	int m; cin >> m;
	for (i = 1; i <= m; i++) {
		int t; cin >> t;
		if (t == 1) {
			int a, b; ll c; cin >> a >> b >> c;
			a++; b++;
			int MIN = min(a, b);
			int MAX = max(a, b);
			update_range(1, n, 1, MIN, MAX, c);
		}
		else {
			int a, b; cin >> a >> b;
			a++; b++;
			int MIN = min(a, b);
			int MAX = max(a, b);
			cout << sum(1, n, 1, MIN, MAX) << "\n";
		}
	}
	return 0;
}