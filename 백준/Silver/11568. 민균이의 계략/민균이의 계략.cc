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
using namespace std;

int arr[N];
int dp[N];


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, j; //for문 변수 -> longlong필요한지 확인
	int n; cin >> n;
	dp[1] = 1;
	for (i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	int m = 1;
	for (i = 2; i <= n; i++) {
		dp[i] = 1; 
		for (j = 1; j < i; j++) {
			if (arr[i] > arr[j]) {
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
		m = max(m, dp[i]);
	}
	cout << m;
	return 0;

}