#include <iostream>
#include <algorithm>
#include <functional>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <string>
#include <queue>
#include <stack>
#include <map>
#include <vector>
#include <set>
#include <sstream>
#include <ctime>

using namespace std;


int arr[105];
long long dp[105][105];
int n;
long long DP(int now,int calculated) {
	if (now == n) {
		if (calculated == arr[n]) {
			return 1;
		}
		return 0;
	}

	long long ret = 0;
	int temp = calculated + arr[now];
	if (temp >= 0 && temp <= 20) {
		if (dp[now][temp] != -1) ret += dp[now][temp];
		else {
			dp[now][temp] =  DP(now + 1, temp);
			ret += dp[now][temp];
		}
	}
	temp = calculated - arr[now];
	if (temp >= 0 && temp <= 20) {
		if (dp[now][temp] != -1) ret += dp[now][temp];
		else {
			dp[now][temp] = DP(now + 1, temp);
			ret += dp[now][temp];
		}
	}
	return ret;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, j; //for문 변수 -> longlong필요한지 확인
	cin >> n;
	for (i = 1; i <= n; i++) {
		cin >> arr[i];
		for (j = 0; j <= 20; j++) {
			dp[i][j] = -1;
		}
	}
	cout << DP(2, arr[1]);
	return 0;
}