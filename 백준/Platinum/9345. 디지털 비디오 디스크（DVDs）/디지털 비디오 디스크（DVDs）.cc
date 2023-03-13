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
ll treeM[4 * N];
ll treem[4 * N];

ll init(int start, int end, int node, ll* tree, int flag) {
	if (start == end) return tree[node] = arr[start];
	int mid = MID(start, end);
	if (flag) {
		return tree[node] = max(init(start, mid, node * 2, tree, flag), init(mid + 1, end, node * 2 + 1, tree, flag));
	}
	else {
		return tree[node] = min(init(start, mid, node * 2, tree, flag), init(mid + 1, end, node * 2 + 1, tree, flag));
	}
}

ll Max(int start, int end, int node, int left, int right) {
	if (end<left || start > right) return 0;
	if (left <= start && end <= right) return treeM[node];
	int mid = MID(start, end);
	return max(Max(start, mid, node * 2, left, right), Max(mid + 1, end, node * 2 + 1, left, right));
}

ll Min(int start, int end, int node, int left, int right) {
	if (end<left || start > right) return 987654321;
	if (left <= start && end <= right) return treem[node];
	int mid = MID(start, end);
	return min(Min(start, mid, node * 2, left, right), Min(mid + 1, end, node * 2 + 1, left, right));
}

void update(int start,int end, int node, int idx, ll diff,ll* tree, int flag){
	if (idx<start || idx>end) return;
	if (start == end) {
		tree[node] = diff;
		return;
	}
	int mid = MID(start, end);
	update(start, mid, node * 2, idx, diff, tree, flag);
	update(mid + 1, end, node * 2 + 1, idx, diff, tree, flag);
	if (flag) {
		tree[node] = max(tree[node * 2], tree[node * 2 + 1]);
	}
	else {
		tree[node] = min(tree[node * 2], tree[node * 2 + 1]);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, j; //for문 변수 -> longlong필요한지 확인
	int  T; cin >> T;
	while (T--) {
		int n, k; cin >> n >> k;
		for (i = 1; i <= n; i++) {
			arr[i] = i;
		}
		init(1, n, 1, treeM, 1);
		init(1, n, 1, treem, 0);

		for (i = 1; i <= k; i++) {
			int cmd; cin >> cmd;
			if (cmd == 0) {
				int a, b; cin >> a >> b;
				a++; b++;
				update(1, n, 1, a, arr[b], treeM, 1);
				update(1, n, 1, b, arr[a], treeM, 1);
				update(1, n, 1, a, arr[b], treem, 0);
				update(1, n, 1, b, arr[a], treem, 0);
				ll temp = arr[a];
				arr[a] = arr[b];
				arr[b] = temp;
			}
			else {
				int a, b; cin >> a >> b;
				a++, b++;
				ll M = Max(1, n, 1, a, b);
				ll m = Min(1, n, 1, a, b);
				//cout << M << " " << m << endl;
				if (a == m && b == M) {
					cout << "YES\n";
				}
				else {
					cout << "NO\n";
				}
			}
		}
		for (i = 1; i <= n; i++) {
			arr[i] = 0;
		}
		for (i = 1; i <= 4 * n; i++) {
			treeM[i] = 0;
			treem[i] = 0;
		}
	}

	return 0;
}