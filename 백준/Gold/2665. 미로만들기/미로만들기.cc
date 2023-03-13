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

int n;
bool ok(int y, int x) {
	if (y < 1 || y>n || x<1 || x>n) return false;
	return true;
}
int dx[] = { 0, 1, 0, -1 };
int dy[] = { 1, 0, -1, 0 };
int arr[55][55];
int dp[55][55];
queue<int> qx;
queue<int> qy;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, j; //for문 변수 -> longlong필요한지 확인
	//int n; cin >> n;
	scanf("%d", &n);
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++) {
			scanf("%1d", &arr[i][j]);
			dp[i][j] = 987654321;
		}	
	}
	qx.push(1);
	qy.push(1);
	dp[1][1] = 0;
	while (!qx.empty() && !qy.empty()) {
		int nowx = qx.front(); qx.pop();
		int nowy = qy.front(); qy.pop();
		int wall = dp[nowy][nowx];
		for (i = 0; i < 4; i++) {
			int ty = nowy + dy[i];
			int tx = nowx + dx[i];
			if (ok(ty, tx)) {
				if (arr[ty][tx] == 0 && dp[ty][tx] > wall + 1) {
					dp[ty][tx] = wall + 1;
					qx.push(tx);
					qy.push(ty);
				}
				else if(arr[ty][tx] == 1 && dp[ty][tx] > wall) {
					dp[ty][tx] = wall;
					qx.push(tx);
					qy.push(ty);
				}
			}
		}
	}
	cout << dp[n][n];
	return 0;
}