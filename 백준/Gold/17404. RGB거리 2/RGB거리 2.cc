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

int dp[N][5][5];
int color[N][5];

void Solution(int n) {
	dp[1][0][0] = color[1][0];
	dp[1][0][1] = INF;
	dp[1][0][2] = INF;

	dp[1][1][0] = INF;
	dp[1][1][1] = color[1][1];
	dp[1][1][2] = INF;

	dp[1][2][0] = INF;
	dp[1][2][1] = INF;
	dp[1][2][2] = color[1][2];
	
	dp[2][0][0] = INF;
	dp[2][1][0] = dp[1][0][0] + color[2][1];
	dp[2][2][0] = dp[1][0][0] + color[2][2];

	dp[2][0][1] = dp[1][1][1] + color[2][0];
	dp[2][1][1] = INF;
	dp[2][2][1] = dp[1][1][1] + color[2][2];

	dp[2][1][2] = dp[1][2][2] + color[2][1];
	dp[2][0][2] = dp[1][2][2] + color[2][0];
	dp[2][2][2] = INF;

	for (int i = 3; i < n; i++) {
		dp[i][0][0] = min(dp[i - 1][1][0], dp[i - 1][2][0]) + color[i][0];
		dp[i][0][1] = min(dp[i - 1][1][1], dp[i - 1][2][1]) + color[i][0];
		dp[i][0][2] = min(dp[i - 1][1][2], dp[i - 1][2][2]) + color[i][0];
		//dp[i][0][1] = dp[i][0][2] = dp[i][0][0];
		
		dp[i][1][0] = min(dp[i - 1][0][0], dp[i - 1][2][0]) + color[i][1];
		dp[i][1][1] = min(dp[i - 1][0][1], dp[i - 1][2][1]) + color[i][1];
		dp[i][1][2] = min(dp[i - 1][0][2], dp[i - 1][2][2]) + color[i][1];
		//dp[i][1][2] = dp[i][1][0] = dp[i][1][1];


		dp[i][2][0] = min(dp[i - 1][1][0], dp[i - 1][0][0]) + color[i][2];
		dp[i][2][1] = min(dp[i - 1][1][1], dp[i - 1][0][1]) + color[i][2];
		dp[i][2][2] = min(dp[i - 1][1][2], dp[i - 1][0][2]) + color[i][2];
		//dp[i][2][0] = dp[i][2][1] = dp[i][2][2];
	}
	dp[n][0][0] = INF;
	dp[n][0][1] = min(dp[n - 1][1][1], dp[n - 1][2][1]) + color[n][0];
	dp[n][0][2] = min(dp[n - 1][1][2], dp[n - 1][2][2]) + color[n][0];

	dp[n][1][0] = min(dp[n - 1][2][0], dp[n - 1][0][0]) + color[n][1];
	dp[n][1][1] = INF;
	dp[n][1][2] = min(dp[n - 1][2][2], dp[n - 1][0][2]) + color[n][1];

	dp[n][2][0] = min(dp[n - 1][1][0], dp[n - 1][0][0]) + color[n][2];
	dp[n][2][1] = min(dp[n - 1][1][1], dp[n - 1][0][1]) + color[n][2];
	dp[n][2][2] = INF;
	
	int min0 = min(dp[n][0][1], dp[n][0][2]);
	int min1 = min(dp[n][1][0], dp[n][1][2]);
	int min2 = min(dp[n][2][0], dp[n][2][1]);

	cout << min(min0, min(min1, min2)) << endl;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, j; //for문 변수 -> longlong필요한지 확인
	int n; cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> color[i][0] >> color[i][1] >> color[i][2];
	}
	Solution(n);
	return 0;
}