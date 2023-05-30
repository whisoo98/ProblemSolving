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
#define N 1'500'005
#define ll long long
#define endl "\n"
#define MID(a,b) (a+b)/2

using namespace std;

pair<int, int> counseling[N];
int dp[N];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, j; //for문 변수 -> longlong필요한지 확인
	int n; cin >> n;
	for (int i = 1; i <= n; i++) {
		int a, b; cin >> a >> b;
		counseling[i] = { a,b };
	}
	for (int i = 1; i <= n; i++) {
		dp[i] = max(dp[i - 1], dp[i]);
		if (i + counseling[i].first > n + 1) {
			continue;
		}
		else {
			dp[i + counseling[i].first] 
				= max(dp[i + counseling[i].first], dp[i] + counseling[i].second);
		}
	}
	i = n + 1;
	dp[i] = max(dp[i - 1], dp[i]);
	cout << dp[n + 1] << endl;
	return 0;
}