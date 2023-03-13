#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <functional>
#include <stdlib.h>
#include <string>
#include <queue>
#include <stack>
#include <map>
#include <climits>
#include <cstring>


using namespace std;

/*struct type_name {

}srt;*/

//vector <type> vec;
//stack <type> stk;
//queue <type> q;
//string str;
//map <key_type,value_type> m;

int arr[105];
int dp[105][1005];
int n, start, M;
int m = -1;
/*bool ok(int x) { //이론적으로는 백트래킹 방법이 가능하지만 백트래킹자체가 전수조사형이라서 2의 100승의 경우의수를 전부 체크하면 시간초과가 생긴다.
	if (x<0 || x>M) return false;
	return true;
}
void back(int level) {
	cout << "!";
	if (m == M) return;
	if (level == n) {
		if (ok(dp[level])) m = max(m, dp[level]);
		return;
	}
	if (!ok(dp[level])) return;

	dp[level + 1] = dp[level] + arr[level + 1];
	back(level + 1);
	dp[level + 1] = dp[level] - arr[level + 1];
	back(level + 1);
}*/

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int i, j;//for문변수-->가끔식 long으로
	scanf("%d %d %d", &n, &start, &M);
	for (i = 1; i <= n; i++) scanf("%d", &arr[i]);
	for (i = 0; i <= n+1; i++) {
		for (j = 0; j <= M; j++) {
			dp[i][j] = -1;
		}
	}
	arr[0] = start;
	dp[0][start] = start;
	for (i = 0; i <= n; i++) {
		for (j = 0; j <= M; j++) {
			if (dp[i][j] >= 0) {
				if (j + arr[i + 1] >= 0 && j + arr[i + 1] <= M) dp[i + 1][j + arr[i + 1]] = dp[i][j] + arr[i + 1];
				if (j - arr[i + 1] >= 0 && j - arr[i + 1] <= M) dp[i + 1][j - arr[i + 1]] = dp[i][j] - arr[i + 1];
			}
		}
	}

	
	for (j = M; j >= 0; j--) {
		if (dp[n + 1][j] >= 0) {
			printf("%d", j);
			return 0;
		}
	}
	printf("-1");
	//top_memo(0, n);

	return 0;
}