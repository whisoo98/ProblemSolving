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
using namespace std;

long long arr[N];
int pos[2 * N];
long long tree[4 * N];

long long init(int start, int end, int node) {
	if (start == end) return tree[node] = arr[start];
	int mid = (start + end) / 2;
	return tree[node] = init(start, mid, node * 2) + init(mid + 1, end, node * 2 + 1);
}

long long sum(int start, int end, int node, int left, int right) {
	if (right < start || end < left) return 0;
	if (left <= start && end <= right) return tree[node];
	int mid = (start + end) / 2;
	return sum(start, mid, node * 2, left, right) + sum(mid + 1, end, node * 2 + 1, left, right);
}

void update(int start, int end, int node, int idx, long long diff) {
	if (idx < start || end < idx) return;
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
	int n; cin >> n;
	for (i = 1; i <= n; i++) {
		int a; cin >> a;
		arr[i] = 1;
		pos[a] = i;
	}
	init(1, n, 1);
	long long cnt = 0;
	for (i = 1; i <= n; i++) {
		int a; cin >> a;
		cnt += sum(1, n, 1, 1, pos[a] - 1);
		update(1, n, 1, pos[a], -1);
	}
	cout << cnt;
	return 0;
}