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
#define N 1000000+5
#define ll long long
#define endl "\n"
#define MID(a,b) (a+b)/2
#define MOD 1000000007
using namespace std;
//const long long int MOD = 1000000007;

ll dp[N][3];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, j; //for문 변수 -> longlong필요한지 확인
	int n; cin >> n;
	if (n == 1) {
		cout << 3;
		return 0;
	}
	else if (n == 2) {
		cout << 11;
		return 0;
	}
	else {
		


			ll ans = 1;
			for (i = 1; i <= n + 2; i++) {
				ans *= 2;
				ans %= MOD;
			}
			cout << (ans%MOD + MOD - 5) % MOD << endl;
		
	}
	/*dp[1][0] = 3;
	dp[1][1] = 2;
	dp[1][2];
	dp[2][0] = 11;
	dp[2][1] = 6;
	dp[2][2] = 6;
	for (i = 3; i <= n; i++) {
		dp[i][1] = (dp[i - 1][1] * 2 + 2) % MOD;
		dp[i][0] = (dp[i - 1][0] * 2 + dp[i - 1][1] + 4) % MOD;
	}

	cout << dp[n][0];*/


	return 0;
}