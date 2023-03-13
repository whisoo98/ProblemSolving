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

using namespace std;

long long arr[N];
long long tree[4 * N];
long long lazy[4 * N];

long long init(int start,int end,int node){
	if (start == end) return tree[node] = arr[start];
	int mid = (start + end) / 2;
	return tree[node] = init(start, mid, node * 2) + init(mid + 1, end, node * 2 + 1);
}

long long sum(int start, int end, int node, int left, int right) {
	if (lazy[node] != 0) {
		tree[node] += (end - start + 1)*lazy[node];
		if (start != end) {
			lazy[node * 2] += lazy[node];
			lazy[node * 2 + 1] += lazy[node];
		}
		lazy[node] = 0;
	}
	if (right<start || left>end) return 0;
	if (left <= start && end <= right) return tree[node];
	int mid = (start + end) / 2;
	return sum(start, mid, node * 2, left, right) + sum(mid + 1, end, node * 2 + 1, left, right);
}

void update(int start, int end, int node, int idx, long long diff) {
	if (idx<start || idx>end) return;
	tree[node] += diff;
	if (start == end) return;
	int mid = (start + end) / 2;
	update(start, mid, node * 2, idx, diff);
	update(mid + 1, end, node * 2 + 1, idx, diff);
	tree[node] = tree[node * 2] + tree[node * 2 + 1];
}

void update_range(int start, int end, int node, int left, int right, long long diff) {
	if (lazy[node] != 0) {
		tree[node] += (end - start + 1)*lazy[node];
		if (start != end) {
			lazy[node * 2] += lazy[node];
			lazy[node * 2 + 1] += lazy[node];
		}
		lazy[node] = 0;
	}

	if (right<start || left>end) return;

	if (left <= start && end <= right) {
		tree[node] += (end - start + 1)*diff;
		if (start != end) {
			lazy[node * 2] += diff;
			lazy[node * 2 + 1] += diff;
		}
		return;
	}
	int mid = (start + end) / 2;
	update_range(start, mid, node * 2, left, right, diff);
	update_range(mid + 1, end, node * 2 + 1, left, right, diff);
	
	tree[node] = tree[node * 2] + tree[node * 2 + 1];
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
		int cmd; cin >> cmd;
		if (cmd == 1) {
			int b, c;
			long long d; 
			//cin >> b >> c >> d;
			cin >> b >> c;
			cin >> d;
			update_range(1, n, 1, b, c, d);
		}
		else if (cmd == 2) {
			int b, c; cin >> b >> c;
			cout << sum(1, n, 1, b, c) << "\n";
		}
	}
	return 0;
}