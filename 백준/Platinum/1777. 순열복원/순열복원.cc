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
#define N 100005
#define ll long long
#define endl "\n"
#define MID(a,b) (a+b)/2

using namespace std;

ll arr[N];
ll tree[4*N];
ll brr[N];
ll answer[N];
ll init(int start, int end, int node) {
	if (start == end) return tree[node] = arr[start];
	int mid = MID(start, end);
	return tree[node] = init(start, mid, node * 2) + init(mid + 1, end, node * 2 + 1);
}

ll sum(int start, int end, int node, int left, int right) {
	if (right<start || left > end) return 0;
	if (left <= start && end <= right) return tree[node];
	int mid = MID(start, end);
	return sum(start, mid, node * 2, left, right) + sum(mid + 1, end, node * 2 + 1, left, right);
}

void update(int start, int end, int node, int idx, ll diff) {
	if (idx<start || idx>end) return;
	tree[node] += diff;
	if (start == end) return;
	int mid = MID(start, end);
	update(start, mid, node * 2, idx, diff);
	update(mid + 1, end, node * 2 + 1, idx, diff);
}

void query(int start, int end, int node, ll cnt, ll* ans) {
	if (start == end) {
		*ans = start;
		return;
	}

	int mid = MID(start, end);
	ll L = sum(start, mid, node * 2, start, mid);
	ll R = sum(mid + 1, end, node * 2 + 1, mid + 1, end);
	if (R >= cnt) {
		query(mid + 1, end, node * 2 + 1, cnt, ans);
	}
	else {
		query(start, mid, node * 2, cnt - R, ans);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, j; //for문 변수 -> longlong필요한지 확인
	int n; cin >> n;
	for (i = 1; i <= n; i++) {
		cin >> brr[i];
		brr[i]++;
		arr[i]=1;
		//update(1, n, 1, i, arr[i]);
	}
	init(1, n, 1);

	for (i = n; i >= 1; i--) {
		ll ans;
		query(1, n, 1, brr[i], &ans);
		answer[ans] = i;
		update(1, n, 1, (int)ans, -1);
		//cout << ans << endl;
	}
	for (i = 1; i <= n; i++) {
		cout << answer[i] << " ";
	}
	return 0;
}