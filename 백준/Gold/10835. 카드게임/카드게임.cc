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
#define N 2005

using namespace std;

int arr[N];
int brr[N];
int dp[N][N];
int n;

int Find(int left, int right) {
	if (left < 1 || right < 1) return 0;
	if (dp[left][right] != -1) return dp[left][right];
	dp[left][right] = 0;
	int temp1 = 0, temp2 = 0, temp3 = 0;
	if (arr[left] > brr[right]) {
		temp1 = Find(left, right - 1) + brr[right];
		//dp[left][right] = max(dp[left][right], temp1);
	}
	temp2 = max(Find(left - 1, right - 1), Find(left - 1, right));
	int M = max(temp1, temp2);
	dp[left][right] += M;
	//printf("left : %d, right : %d, temp1 : %d, temp2 : %d\n", left, right, temp1, temp2);
	return dp[left][right];
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, j; //for문 변수 -> longlong필요한지 확인
	 cin >> n;
	for (i = n; i >= 1; i--) {
		cin >> arr[i];
	}
	for (i = n; i >= 1; i--) {
		cin >> brr[i];
	}
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++) {
			dp[i][j] = -1;
		}
	}
	cout << Find(n, n);
	return 0;
}