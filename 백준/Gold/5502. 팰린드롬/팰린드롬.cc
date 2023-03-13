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
#define N 5005
using namespace std;

int dp[N][N];
char arr[N];
char brr[N];


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, j; //for문 변수 -> longlong필요한지 확인
	int n; cin >> n;
	for (i = 1; i <= n; i++) {
		char a; cin >> a;
		arr[i] = a;
		brr[n + 1 - i] = a;
	}
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++) {
			dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			if(arr[i]==brr[j]){
				dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 1);
			}
		}
	}
	cout << n-dp[n][n];
	return 0;
}