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
ll sum[N];
ll ans;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, j; //for문 변수 -> longlong필요한지 확인
	int n; cin >> n;
	for (i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	sum[1] = arr[1];
	for (i = 2; i <= n; i++) {
		sum[i] = sum[i - 1] + arr[i];
	}
	for (i = 1; i <= n; i++) {
		ans += arr[i] * (sum[n] - sum[i]);
	}
	cout << ans;
	return 0;
}