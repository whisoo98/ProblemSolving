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
#define N 1005
#define ll long long
#define endl "\n"
#define MID(a,b) (a+b)/2
#define INF 987654321
using namespace std;

int arr[N];
int cost[N];
int dp[N][N];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, j; //for문 변수 -> longlong필요한지 확인
	int n; cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> cost[i];
	}
	for (int i = 0; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			dp[i][j] = INF;
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (j >= i) {
				dp[i][j] = min(dp[i - 1][j], dp[i][j - i] + cost[i]);
			}
			else {
				dp[i][j] = dp[i - 1][j];
			}
		}
	}
	cout << dp[n][n] << endl;
	return 0;
}