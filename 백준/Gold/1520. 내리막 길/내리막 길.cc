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
#define N 505
#define INF 987654321
#define ll long long
#define endl "\n"
#define MID(a,b) (a+b)/2

using namespace std;

int arr[N][N];
int visit[N][N];
int reachable[N][N];
bool ok(int ty, int tx, int y, int x) {
	if (ty<1 || ty>y || tx<1 || tx>x) return false;
	return true;
}
ll cnt;
int dfs(int nowy,int nowx, int y, int x) {
	if (nowy == y && nowx == x) {
		return reachable[y][x];
	}
	else if (reachable[nowy][nowx]!=-1) {
		return  reachable[nowy][nowx];
	}
	reachable[nowy][nowx] = 0;
	visit[nowy][nowx] = 1;
	int ret=0;
	int dy[] = { 0,0,1,-1 };
	int dx[] = { 1,-1,0,0 };
	for (int i = 0; i < 4; i++) {
		int chk = 0;
		int ty = nowy + dy[i];
		int tx = nowx + dx[i];
		if (ok(ty, tx, y, x)){
			if (!visit[ty][tx] && arr[ty][tx] < arr[nowy][nowx]) {
				chk = dfs(ty, tx, y, x);
			}
		}
		else reachable[ty][tx] = 0;
		ret += chk;

	}
	visit[nowy][nowx] = 0;
	reachable[nowy][nowx] =ret;
	return ret;

}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, j; //for문 변수 -> longlong필요한지 확인
	int y, x; cin >> y >> x;
	
	for (i = 1; i <= y; i++) {
		for (j = 1; j <= x; j++) {
			cin >> arr[i][j];
			reachable[i][j] = -1;
		}
	}
	reachable[y][x] = 1;

	dfs(1,1,y, x);
	cout << reachable[1][1];
	return 0;
}