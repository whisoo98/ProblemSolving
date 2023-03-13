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
#define endl "\n"
#define END 1000000000
using namespace std;

ll arr[N];
ll tree[4 * N];
map<ll, int> m;
ll init(int start, int end, int node) {
	if (start == end) return tree[node] = arr[start];
	int mid = MID(start, end);
	return tree[node] = init(start, mid, node * 2) + init(mid + 1, end, node * 2 + 1);
}

ll sum(int start, int end, int node, int left, int right) {
	if (end<left || start>right) return 0;
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

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, j; //for문 변수 -> longlong필요한지 확인
	int n; cin >> n;
	vector<ll> v;
	for (i = 1; i <= n; i++) {
		cin >> arr[i];
		v.push_back(arr[i]);
		/*cout << sum(1, END, 1, 1, (int)arr[i] - 1) + 1 << endl;
		update(1, END, 1, (int)arr[i], 1);*/
	}
	sort(v.begin(), v.end());
	for (i = 0; i < n; i++) {
		m.insert({ v[i],i + 1 });
	}
	for (i = 1; i <= n; i++) {
		int temp = m[arr[i]];
		cout << sum(1, n, 1, temp, n) + 1 << endl;
		update(1, n, 1, temp, 1);
	}



	return 0;
}