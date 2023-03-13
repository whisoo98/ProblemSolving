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

using namespace std;

long long dp[20][20];


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, j; //for문 변수 -> longlong필요한지 확
	int T; cin >> T;
	for (i = 1; i <= 14; i++) {
		dp[0][i] = i;
	}
	for (i = 1; i <= 14; i++) {
		for (j = 1; j <= 14; j++) {
			for (int k = 1; k <= j; k++) {
				dp[i][j] += dp[i - 1][k];
			}
		}
	}
	while (T--) {
		int n, k; cin >> n >> k;
		cout << dp[n][k] << "\n";
	}

	return 0;
}