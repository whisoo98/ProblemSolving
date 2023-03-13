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
#define N 1'000'005
#define ll long long
#define endl "\n"
#define MID(a,b) (a+b)/2

using namespace std;

ll arr[N];


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, j; //for문 변수 -> longlong필요한지 확인
	int n; cin >> n;
	ll b, c;
	for (i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	cin >> b >> c;
	ll ans = 0;
	for (i = 1; i <= n; i++) {
		arr[i] -= b;
		ans++;
		if (arr[i]>0) {
			ll mok = arr[i] / c;
			ll rest = arr[i] % c;
			if (rest) mok++;
			ans += mok;
		}
	}
	cout << ans;
	return 0;
}