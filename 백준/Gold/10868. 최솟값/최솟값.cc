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
#define MAX 1000000005
using namespace std;

int arr[N];
int tree[4 * N];

int init(int start, int end, int node) {
	if (start == end) return tree[node] = arr[start];
	int mid = (start + end) / 2;
	return tree[node] = min(init(start, mid, node * 2),init(mid + 1, end, node * 2 + 1));
}

int query(int start, int end, int node, int left, int right) {
	if (right<start || left > end) return MAX;
	if (left <= start && end <= right) return tree[node];
	int mid = (start + end) / 2;
	return min(query(start, mid, node * 2, left, right), query(mid + 1, end, node * 2 + 1, left, right));
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, j; //for문 변수 -> longlong필요한지 확인
	int n, m; cin >> n >> m;
	for (i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	init(1, n, 1);
	for (i = 1; i <= m; i++) {
		int a, b; cin >> a >> b;
		cout << query(1, n, 1, a, b) << "\n";
	}

	return 0;
}