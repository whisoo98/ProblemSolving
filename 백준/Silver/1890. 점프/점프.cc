#include <stdio.h>
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


using namespace std;

/*struct type_name {

}srt;*/

//vector <type> vec;
//stack <type> stk;
//queue <type> q;
//string str;
//map <key_type,value_type> m;

int n;
int arr[105][105];
long long dp[105][105];
bool ok(int y, int x) {
	if (y < 1 || y>n || x<1 || x>n) return false;
	return true;
}
/*void jump(int y, int x) {
	if (y == n && x == n) return;
	//if (dp[y][x]) return;
	if (ok(y, x + arr[y][x])) {
		dp[y][x + arr[y][x]] += dp[y][x];
		jump(y, x + arr[y][x]);
	}
	if (ok(y + arr[y][x], x)) {
		dp[y+arr[y][x]][x] += dp[y][x];
		jump(y + arr[y][x], x);
	}
}*/

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int i, j;//for문변수-->가끔식 long으로
	scanf("%d", &n);
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++) scanf("%d", &arr[i][j]);
	}
	dp[1][1] = 1;
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++) {
			if (i == n && j == n) continue;
			dp[i + arr[i][j]][j] += dp[i][j];
			dp[i][j + arr[i][j]] += dp[i][j];
		}
	}

	printf("%lld", dp[n][n]);
	return 0;
}