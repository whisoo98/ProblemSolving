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
#define INF 987654321987654321
using namespace std;
ll arr[4 * N];
ll ans;
int n; 

ll init(int left, int right, int node, vector<ll>& h) {
	if (left == right) return arr[node] = left;
	int mid = (left + right) / 2;
	ll L = init(left, mid, node * 2, h);
	ll R = init(mid + 1, right, node * 2 + 1, h);
	//L = 0 ? 998877665544332211 : L;
	//R = 0 ? 998877665544332211 : R;

	return arr[node] = h[L] < h[R]? L:R;
}

ll sum(int left, int right, int start, int end, int node, vector<ll>& h) {
	int mid = (left + right) / 2;
	if (start <= left && right <= end) {
		return arr[node];
	}
	else if (end<left || start >right) {
		return INF;
	}
	ll L = sum(left, mid, start, end, node * 2, h);
	ll R = sum(mid + 1, right, start, end, node * 2 + 1, h);
	if (L == INF) return R;
	else if (R == INF) return L;
	else return h[L] < h[R] ? L : R;
}

void dnc(int left, int right, vector<ll>& h) {
	if (left > right) return;

	ll idx = sum(1, n, left,right,1, h);
	ans = max(ans, h[idx] * (right - left + 1));
	dnc(left, idx - 1, h);
	dnc(idx + 1, right, h);
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, j; //for문 변수 -> longlong필요한지 확인
	while(1){
		cin >> n;
		if (n == 0) break;
		vector<ll> height(4*n);
		for (i = 1; i <= n; i++) {
			ll a; cin >> a;
			height[i] = a;
		}
		init(1, n, 1, height);
		//cout << DNC(1, n, 1) << endl;
		dnc(1, n, height);
		cout << ans << endl;


		ans = 0;
		for (int i = 0; i <= 4 * n; i++) arr[i] = 0;

	}

	return 0;
}