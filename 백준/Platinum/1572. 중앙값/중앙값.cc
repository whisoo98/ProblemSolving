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
#define N 250005
#define ll long long
#define endl "\n"
#define MID(a,b) (a+b)/2
#define MAX 65537
using namespace std;

ll arr[N];
ll tree[4 * N];
ll Sum;

ll init(int start, int end, int node) {
	if (start == end) return tree[node] = arr[start];
	int mid = MID(start, end);
	return tree[node] = init(start, mid, node * 2) + init(mid + 1, end, node * 2 + 1);
}

ll sum(int start, int end, int node, int left, int right) {
	if (right<start || left>end) return 0;
	if (left <= start && end <= right) return tree[node];
	int mid = MID(start, end);
	return sum(start, mid, node * 2, left, right) + sum(mid + 1, end, node * 2 + 1, left, right);
}

void update(int start, int end, int node, int idx, ll diff) {
	if (idx < start || idx > end) return;
	tree[node] += diff;
	if (start == end) return;
	int mid = MID(start, end);
	update(start, mid, node * 2, idx, diff);
	update(mid + 1, end, node * 2 + 1, idx, diff);
}

void query(int start, int end, int node, ll target, ll* ans) {
	//if (tree[node] > target) return;
	if (start == end) {
		*ans = (ll)start;
		//cout << "node : "<<node<<endl;
		//cout << start << endl;
		return;
	}
	int mid = MID(start, end);

	ll L, R;
	L = sum(start, mid, node * 2, start, mid);
	R = sum(mid + 1, end, node * 2 + 1, mid + 1, end);
	//cout << "start & end " << start << " " << end << endl;
	//cout  <<"L & R "<< L << " " << R << endl;
	if (L >= target) {
		//cout << "Into The L" << endl;
		query(start, mid, node * 2, target, ans);
	}
	else {
		//cout << "Into The R" << endl;
		query(mid + 1, end, node * 2 + 1, target-L, ans);
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, j; //for문 변수 -> longlong필요한지 확인
	int n, k; cin >> n >> k;
	ll target = (k + 1) / 2;
	for (i = 1; i <= n; i++) {
		cin >> arr[i];
		arr[i]++;
		update(1, MAX, 1, (int)arr[i], 1);
		if (i < k) {
			continue;
		}
		ll ans=0;
		query(1, MAX, 1, target, &ans);
		update(1, MAX, 1, (int)arr[i - k + 1], -1);
		//cout << "ans : "<<--ans << endl;
		Sum += --ans;
	}
	cout << Sum;

	return 0;
}