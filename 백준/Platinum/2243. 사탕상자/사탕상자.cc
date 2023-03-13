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
#define MAX 1000000
using namespace std;

ll arr[N];
ll tree[4 * MAX+5];

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
	if (idx<start || idx>end) return;
	tree[node] += diff;
	if (start == end) return;
	int mid = MID(start, end);
	update(start, mid, node * 2, idx, diff);
	update(mid + 1, end, node * 2 + 1, idx, diff);
}

void query(int start, int end, int node, ll cnt, ll* ans) {
	if (start == end) {
		//cout << start << " " << node << endl;
		*ans = start;
		return;
	}
	int mid = MID(start, end);
	ll L = sum(start, mid, node * 2, start, mid);
	ll R = sum(mid + 1, end, node * 2 + 1, mid + 1, end);
	//cout << L << " " << R << endl;
	if (L >= cnt) {
		query(start, mid, node * 2, cnt, ans);
	}
	else {
		query(mid + 1, end, node * 2 + 1, cnt - L, ans);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, j; //for문 변수 -> longlong필요한지 확인
	int n; cin >> n;
	
	//init(1, MAX, 1);
	for (i = 1; i <= n; i++) {
		int cmd; cin >> cmd;
		if (cmd == 1) {
			ll b; cin >> b; //꺼낼 사탕의 순위
			ll ans = 0;
			query(1, MAX, 1, b, &ans);
			cout << ans << endl;
			update(1, MAX, 1, (int)ans, -1);
		}
		else {
			int b; ll c; cin >> b >> c; //B 넣을 사탕의 맛, C는 그러한 사탕의 개수
			if (c > 0) {
				update(1, MAX, 1, b, c);
			}
			else {
				update(1, MAX, 1, b, c);
			}
		}
	}

	return 0;
}