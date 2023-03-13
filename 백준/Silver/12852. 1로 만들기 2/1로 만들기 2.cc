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
#define N ((int)1e7+5)
#define ll long long
#define endl "\n"
#define MID(a,b) (a+b)/2

using namespace std;

int track[N];
int dp[N];

void DP(int n) {
	for (int i = 2; i <= n; i++) {
		dp[i] = i - 1; // 횟수
		track[i] = i - 1; // 다음 수
	}
	for (int i = 1; i <= n; i++) {
		int times3 = i * 3;
		int times2 = i * 2;
		int plus1 = i + 1;
		if (dp[i] + 1 < dp[times3]) {
			dp[times3] = dp[i] + 1;
			track[times3] = i;
		}
		if (dp[i] + 1 < dp[times2]) {
			dp[times2] = dp[i] + 1;
			track[times2] = i;
		}
		if (dp[i] + 1 < dp[plus1]) {
			dp[plus1] = dp[i] + 1;
			track[plus1] = i;
		}
	}
	cout << dp[n] << endl;
	int i = n;
	while (i>0) {
		cout << i << " ";
		i = track[i];
	}

}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, j; //for문 변수 -> longlong필요한지 확인
	int n; cin >> n;
	DP(n);
	return 0;
}