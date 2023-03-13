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
#define N 
#define ll long long
#define endl "\n"
#define MID(a,b) (a+b)/2

using namespace std;

int dp[105];


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, j; //for문 변수 -> longlong필요한지 확인
	int n; cin >> n;
	dp[1] = 2;
	dp[2] = 4;
	
	for (i = 3; i <= n; i++) {
		if (i % 2) {
			dp[i] = 2 * dp[i - 1] - dp[i - 2];
		}
		else {
			int mok = i / 2;
			mok++;
			dp[i] = mok * mok;
		}
	}
	cout << dp[n];
	return 0;

}