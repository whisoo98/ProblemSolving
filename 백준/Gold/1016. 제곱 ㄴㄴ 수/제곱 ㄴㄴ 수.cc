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
#define N 3'000'005
#define ll long long
#define endl "\n"
#define MID(a,b) (a+b)/2

using namespace std;

ll arr[N];
ll cnt[N];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	ll i, j; //for문 변수 -> longlong필요한지 확인

	ll m, M; cin >> m >> M;
	ll rootM = (ll)sqrt(M);
	if (rootM*rootM != M) {
		rootM++;
	}
	//cout <<  rootM << endl;

	//cout << rootM * rootM << endl;
	for (i = 2; i<=rootM; i++) {
		ll t = m / (i*i);
		//if (i == rootM) cout << t << endl;

		if (m % (i*i)) t++;
		//if (cnt[t - m]) continue;
		for (j = t*(i*i); j <= M; j+=(i*i)) {
			//if (m > j) cout << j;
			//if (cnt[j - m]) continue;
			cnt[j - m] = 1;
		}	
	}

	ll ans = 0;
	for (i = m; i <= M; i++) {
		if (cnt[i - m] == 0) ans++;

	}
	cout << ans;
	return 0;
}