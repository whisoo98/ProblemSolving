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
#define N 20
#define ll long long
#define endl "\n"
#define MID(a,b) (a+b)/2

using namespace std;

int dp[N][N][3];
int arr[N][N];

bool ok(int ty, int tx,int n) {
	if (ty<1 || ty>n || tx<1 || tx>n || arr[ty][tx]) return false;
	return true;
}

int DNC(int y, int x, int dir, int n) {
	if (y == n && x == n) return 1;
	if (dp[y][x][dir]) return dp[y][x][dir];

	int dy[] = { 0,1,1 };
	int dx[] = { 1,0,1 };
	int ans = 0;
	if (dir == 0) {
		int tdir;
		int ty;
		int tx;
		tdir = 0;
		ty = y + dy[tdir];
		tx = x + dx[tdir];
		if (ok(ty, tx, n)) {
			ans += DNC(ty, tx, tdir, n);
		}
		if (ok(y + 1, x, n) && ok(y, x + 1, n) && ok(y + 1, x + 1, n)) {
			tdir = 2;
			ty = y + dy[tdir];
			tx = x + dx[tdir];
			ans += DNC(ty, tx, tdir, n);
		}
	}
	else if (dir == 1) {
		int tdir;
		int ty;
		int tx;
		tdir = 1;
		ty = y + dy[tdir];
		tx = x + dx[tdir];
		if (ok(ty, tx, n)) {
			ans += DNC(ty, tx, tdir, n);
		}
		if (ok(y + 1, x, n) && ok(y, x + 1, n) && ok(y + 1, x + 1, n)) {
			tdir = 2;
			ty = y + dy[tdir];
			tx = x + dx[tdir];
			ans += DNC(ty, tx, tdir, n);
		}
	}
	else {
		int tdir;
		int ty;
		int tx;
		tdir = 0;
		ty = y + dy[tdir];
		tx = x + dx[tdir];
		if (ok(ty, tx, n)) {
			ans += DNC(ty, tx, tdir, n);
		}
		tdir = 1;
		ty = y + dy[tdir];
		tx = x + dx[tdir];
		if (ok(ty, tx, n)) {
			ans += DNC(ty, tx, tdir, n);
		}
		if (ok(y + 1, x, n) && ok(y, x + 1, n) && ok(y + 1, x + 1, n)) {
			tdir = 2;
			ty = y + dy[tdir];
			tx = x + dx[tdir];
			ans += DNC(ty, tx, tdir, n);
		}
	}
	return dp[y][x][dir] = ans;
}
void Solution(int n) {
	cout << DNC(1, 2, 0, n) << endl;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, j; //for문 변수 -> longlong필요한지 확인
	int n; cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> arr[i][j];
		}
	}
	//dp[1][2][0] = 1;

	Solution(n);
	//cout << dp[n][n][0]+dp[n][n][1] + dp[n][n][2] << endl;
	return 0;
}