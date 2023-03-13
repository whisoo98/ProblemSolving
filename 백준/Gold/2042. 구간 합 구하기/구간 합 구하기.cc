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
#define ll long long
#define endl "\n"
#define MID(a,b) (a+b)/2

using namespace std;

ll arr[N];
ll tree[4 * N];

ll sum(int i) {
	ll ans = 0;
	while (i > 0) {
		ans += tree[i];
		i -= (i&-i);
	}
	return ans;
}

void update(int i, ll num, int n) {
	while (i <= n) {
		tree[i] += num;
		i += (i&-i);
	}
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
		update(i, arr[i], n);
	}
	for (i = 1; i <= m + k; i++) {
		int a; cin >> a;
		if (a % 2) {//update
			int b; ll c; cin >> b >> c;
			ll diff = c - arr[b];
			arr[b] = c;
			update(b, diff, n);
		}
		else {//sum
			int b, c; cin >> b >> c;
			cout << sum(c) - sum(b - 1) << endl;
		}
	}

	return 0;
}