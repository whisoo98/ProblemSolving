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
#define MOD 1'000'000'009
using namespace std;

ll arr[N];
ll dp[N];
void Solution() {
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;
	dp[4] = 7;
	for (int i = 5; i <= 1'000'000; i++) {
		dp[i] = (dp[i - 1] + dp[i - 2] + dp[i - 3])%MOD;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, j; //for문 변수 -> longlong필요한지 확인

	int T; cin >> T;
	Solution();
	while (T--) {
		int n; cin >> n;
		cout << dp[n] << endl;
	}

	return 0;
}