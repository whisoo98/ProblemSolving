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
#define ll long long
#define N 1000005
#define endl "\n"
#define MID(a,b) (a+b)/2

using namespace std;


long long arr[N];
long long tree[4 * N];


long long init(int start, int end, int node) {
	if (start == end) return tree[node] = arr[start];
	int mid = (start + end) / 2;
	return tree[node] = max(init(start, mid, node * 2) , init(mid + 1, end, node * 2 + 1));
}

long long sum(int start, int end, int node, int left, int right) {
	if (left > end || right < start) return 0;
	if (left <= start && end <= right) return tree[node];
	int mid = (start + end) / 2;
	return max(sum(start, mid, node * 2, left, right) , sum(mid + 1, end, node * 2 + 1, left, right));
}




int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, j; //for문 변수 -> longlong필요한지 확인
	int n, q; cin >> n >> q;
	for (i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	init(1, n, 1);
	for (i = q; i <= n - q + 1; i++) {
		cout << sum(1, n, 1, i - q + 1, i + q - 1) << " ";
	}

	return 0;
}