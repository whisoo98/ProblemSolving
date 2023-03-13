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
#define N 200005
#define ll long long
#define endl "\n"
#define MID(a,b) (a+b)/2
#define MOD 1000000007
#define MAX 200000
using namespace std;

ll arr[N];
ll tree[N];
ll cnt[N];

ll sum(int i, ll* tree) {
	ll ans = 0;
	while (i > 0) {
		ans += tree[i];
		i -= (i&-i);
	}
	return ans;
}

void update(int i, ll diff, int n, ll* tree) {
	while (i <= n) {
		tree[i] += diff;
		i += (i&-i);
	}
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, j; //for문 변수 -> longlong필요한지 확인
	int n; cin >> n;
	ll ans = 1;
	for (i = 1; i <= n; i++) {
		
		cin >> arr[i];
		arr[i]++;
		if (i == 1) {
			update(arr[i], 1, MAX, cnt);
			update(arr[i], arr[i], MAX, tree);
			continue;
		}
		ll L, R;
		L = arr[i] * sum(arr[i], cnt) - sum(arr[i], tree);
		R = (sum(MAX, tree) - sum(arr[i], tree)) - arr[i] * (sum(MAX, cnt) - sum(arr[i], cnt));
		//cout << L << " " << R << endl;
		L += R;
		L %= MOD;

		ans *= L;
		ans %= MOD;

		update(arr[i], 1, MAX, cnt);
		update(arr[i], arr[i], MAX, tree);
	}  
	cout << ans;

	
	return 0;
}