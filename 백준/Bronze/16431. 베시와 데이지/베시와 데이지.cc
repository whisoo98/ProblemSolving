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
int visit[2][N][N];
int n=1000;
int by, bx, Dy, Dx;
int dx[] = { 0,0,1,-1,1,1,-1,-1 };
int dy[] = { 1,-1,0,0,1,-1,1,-1 };
bool ok(int ty, int tx) {
	if (ty < 1 || ty>n || tx<1 || tx>n) return false;
	else return true;
}
void dfs(int y, int x, int flag) {
	int i;
	
	if (flag) {
		if (visit[flag][by][bx] != 987654321) return;
		for (i = 0; i < 8; i++) {
			int yy = y + dy[i];
			int xx = x + dx[i];
			if (ok(yy, xx) && visit[flag][yy][xx] > visit[flag][y][x] + 1) {
				visit[flag][yy][xx] = visit[flag][y][x] + 1;
				dfs(yy, xx, flag);
			}
		}
	}
	else {
		if (visit[flag][Dy][Dx] != 987654321) return;
		for (i = 0; i < 4; i++) {
			int yy = y + dy[i];
			int xx = x + dx[i];
			if (ok(yy, xx) && visit[flag][yy][xx] > visit[flag][y][x] + 1) {
				visit[flag][yy][xx] = visit[flag][y][x] + 1;
				dfs(yy, xx, flag);
			}
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, j; //for문 변수 -> longlong필요한지 확인
	for (i = 1; i <= 1000; i++) {
		for (j = 1; j <= 1000; j++) {
			visit[0][i][j] = 987654321;
			visit[1][i][j] = 987654321;
		}
	}
	//int a, b; cin >> a >> b;
	//arr[a][b] = 1;
	int y, x;
	cin >> by >> bx;

	cin >> Dy >> Dx;
	
	cin >> y >> x;

	
	

	//arr[a][b] = (int)'D';
	visit[1][y][x] = 1;
	visit[0][y][x] = 1;
	queue<pair<int, int>>q;
	q.push({ y,x });
	while (!q.empty()) {
		int ty = q.front().first;
		int tx = q.front().second;
		q.pop();
		if (visit[1][by][bx] != 987654321) {
			break;
		}
		for (i = 0; i < 8; i++) {
			int yy = ty + dy[i];
			int xx = tx + dx[i];
			if (ok(yy, xx) && visit[1][yy][xx] > visit[1][ty][tx] + 1) {
				visit[1][yy][xx] = visit[1][ty][tx] + 1;
				q.push({ yy,xx });
			}
		}
	}
	while (!q.empty()) q.pop();
	q.push({ y,x });
	while (!q.empty()) {
		int ty = q.front().first;
		int tx = q.front().second;
		q.pop();
		if (visit[0][Dy][Dx] != 987654321) {
			break;
		}
		for (i = 0; i < 4; i++) {
			int yy = ty + dy[i];
			int xx = tx + dx[i];
			if (ok(yy, xx) && visit[0][yy][xx] > visit[0][ty][tx] + 1) {
				visit[0][yy][xx] = visit[0][ty][tx] + 1;
				q.push({ yy,xx });
			}
		}
	}

	//dfs(y, x, 1);
	//dfs(y, x, 0);
	if (visit[1][by][bx] > visit[0][Dy][Dx]) {
		cout << "daisy";
	}
	else if (visit[1][by][bx] == visit[0][Dy][Dx]) {
		cout << "tie";
	}
	else {
		cout << "bessie";
	}
	return 0;
}