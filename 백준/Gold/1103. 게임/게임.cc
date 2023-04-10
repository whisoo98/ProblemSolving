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
#define N 80
#define ll long long
#define endl "\n"
#define MID(a,b) (a+b)/2

using namespace std;

int dy[] = { 1,-1,0,0 };
int dx[] = { 0,0,1,-1 };

int board[N][N];
int visit[N][N];
int dp[N][N];
int ans =0;

bool isOk(int ty, int tx, int y, int x) {
	if (ty<1 || ty>y || tx<1 || tx>x || board[ty][tx] == 'H') return false;
	return true;
}

int game(int nowy,int nowx,int y, int x, int lv, int cnt) {
	if (ans == -1) return 0;
	//ans = max(ans, lv);
	if (dp[nowy][nowx]) return dp[nowy][nowx];
	int value = 0;
	for (int dir = 0; dir < 4; dir++) {
		int movey = board[nowy][nowx] * dy[dir];
		int movex = board[nowy][nowx] * dx[dir];
		int ty = nowy + movey;
		int tx = nowx + movex;
		if (isOk(ty, tx, y, x)) {
			if (visit[ty][tx]) {
				ans = -1;
				return 0;
			}
			visit[ty][tx] = 1;
			game(ty, tx, y, x, lv + 1, 0);
			value = max(value, dp[ty][tx] + 1);
			visit[ty][tx] = 0;
		}
		else {
			value = max(1,value);
		}
	}
	return dp[nowy][nowx] = value;
}

void Solution(int y, int x) {
	visit[1][1] = 1;
	game(1, 1, y, x, 1, 0);
	if (ans)
		cout << ans << endl;
	else
		cout << dp[1][1] << endl;
	//cout << ans << endl;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, j; //for문 변수 -> longlong필요한지 확인
	int y, x; cin >> y >> x;
	for (int i = 0; i < y; i++) {
		string s; cin >> s;
		for (int j = 0; j < x; j++) {
			if (s[j] - 'H')
				board[i + 1][j + 1] = s[j] - '0';
			else
				board[i + 1][j + 1] = 'H';
		}
	}
	Solution(y, x);
	return 0;
}