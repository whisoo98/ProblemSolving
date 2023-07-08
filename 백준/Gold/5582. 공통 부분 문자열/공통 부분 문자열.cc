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
#define N 4005
#define ll long long
#define endl "\n"
#define MID(a,b) (a+b)/2

using namespace std;


int dp[N][N];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, j; //for문 변수 -> longlong필요한지 확인
	string s1, s2; cin >> s1 >> s2;
	int n = s1.size();
	int m = s2.size();
	int ans = -1;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (s1[i - 1] == s2[j - 1])
				dp[i][j] = dp[i - 1][j - 1] + 1;
			else {
				dp[i][j] = 0;
			}
		ans = max(ans, dp[i][j]);
		}
	}
	cout << ans << endl;

	return 0;
}