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
#define N 100'005
#define ll long long
#define endl "\n"
#define MID(a,b) (a+b)/2
#define MOD 1'000'000'009
using namespace std;

int dp[N][5];

void Preprocess() {
	dp[1][1] = 1; // 1 = 1

	dp[2][2] = 1; // 2 = 2

	dp[3][1] = 1; // 3 = 2 + 1
	dp[3][2] = 1; // 3 = 1 + 2
	dp[3][3] = 1; // 3 = 3

	dp[4][1] = 2; // 4 = 3 + 1, 1 + 2 + 1
	dp[4][3] = 1; // 4 = 1 + 3

	dp[5][1] = 1; // 5 = 1 + 3 + 1
	dp[5][2] = 2; // 5 = 2 + 1 + 2, 3 + 2
	dp[5][3] = 1; // 5 = 2 + 3

	dp[6][1] = 3; // 6 = 2 + 1 + 2 + 1, 3 + 2 + 1, 2 + 3 + 1
	dp[6][2] = 3; // 6 = 3 + 1 + 2, 1 + 2 + 1 + 2, 1 + 3 + 2
	dp[6][3] = 2; // 6 = 2 + 1 + 3, 1 + 2 + 3

	for (int i = 7; i <= 100'000; i++) {
		dp[i][1] = (dp[i - 1][2] + dp[i - 1][3])%MOD;
		dp[i][2] = (dp[i - 2][1] + dp[i - 2][3])%MOD;
		dp[i][3] = (dp[i - 3][1] + dp[i - 3][2])%MOD;
	}
	
}
void Solution(int n) {
	cout << ((dp[n][1] % MOD + dp[n][2] % MOD) % MOD + dp[n][3] % MOD) % MOD << endl;
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, j; //for문 변수 -> longlong필요한지 확인
	int T; cin >> T;
	Preprocess();
	while (T--) {
		int n; cin >> n;
		Solution(n);
	}
	
	return 0;
}