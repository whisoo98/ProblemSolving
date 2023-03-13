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
#define N 105
using namespace std;

int score[105];
int Time[105];
int dp[105][10005];


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, j; //for문 변수 -> longlong필요한지 확인
	int n, T; cin >> n >> T;
	for (i = 1; i <= n; i++) {
		cin >> Time[i] >> score[i];
		for (j = 0; j <= T; j++) {
			if (j >= Time[i]) {
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - Time[i]] + score[i]);
			}
			else {
				dp[i][j] = dp[i - 1][j];
			}
		}
	}
	sort(dp[n], dp[n] + T + 1, greater<int>());
	cout << dp[n][0];
	return 0;
}