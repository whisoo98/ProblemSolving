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
	//int y, x; cin >> y >> x;
	int y, x; scanf("%d %d", &y, &x);
	for (i = 1; i <= y; i++) {
		for (j = 1; j <= x; j++) {
			scanf("%1d", &arr[i][j]);
		}
	}
	int M = 0;
	for (i = 1; i <= y; i++) {
		for (j = 1; j <= x; j++) {
			if (arr[i][j]) {
				int m;
				m = min(dp[i - 1][j], dp[i][j - 1]);
				m = min(dp[i - 1][j - 1], m);
				m++;
				dp[i][j] = m;
				M = max(M, m);
			}
		}
	}
	cout << M*M;

	return 0;
}