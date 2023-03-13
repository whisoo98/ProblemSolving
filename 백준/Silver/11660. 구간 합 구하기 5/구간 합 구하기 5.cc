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
#define N 1050
#define ll long long
#define endl "\n"
#define MID(a,b) (a+b)/2

using namespace std;

int arr[N][N];
int dp[N][N];



int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, j; //for문 변수 -> longlong필요한지 확인

	int n; int q; cin >> n >> q;
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++) {
			cin >> arr[i][j];
			dp[i][j] = dp[i][j - 1] + arr[i][j];
		}
	}
	for (i = n; i > 0; i--) {
		for (j = 1; j <= n; j++) {
			dp[i][j] += dp[i + 1][j];
		}
	}
		while (q--) {
		int x1, y1, x2, y2; cin >> y1 >> x1 >> y2 >> x2;
		int y3, x3, y4, x4;
		y3 = y1, x3 = x2;
		y4 = y2, x4 = x1;
		int ans = dp[y3][x3] - dp[y4 + 1][x3] - dp[y3][x4 - 1] + dp[y4 + 1][x4 -1 ];
		cout << ans << endl;;
	}
	return 0;
}