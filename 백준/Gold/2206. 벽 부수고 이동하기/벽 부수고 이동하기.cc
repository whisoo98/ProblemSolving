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
#define N 100'5
#define ll long long
#define endl "\n"
#define MID(a,b) (a+b)/2
#define INF 987654321

using namespace std;

int arr[N][N];
int visit[N][N][2];

bool ok(int ty, int tx, int y, int x) {
	if (ty<1 || ty>y || tx<1 || tx>x) return false;
	return true;
}

void bfs(int y, int x) {
	visit[1][1][0] = 1;
	queue<int> qx, qy;
	qx.push(1); qy.push(1);
	int dx[] = { 0,0,1,-1 };
	int dy[] = { 1,-1,0,0 };
	while (qx.size()) {
		int nowx = qx.front();
		int nowy = qy.front();
		qx.pop(); qy.pop();
		if(nowx==x && nowy==y) break;
		for (int i = 0; i < 4; i++) {
			int ty = nowy + dy[i];
			int tx = nowx + dx[i];
			if (ok(ty, tx, y, x)) {
				if (arr[ty][tx]) {
					if (visit[ty][tx][1] > visit[nowy][nowx][0] + 1) {
						visit[ty][tx][1] = visit[nowy][nowx][0] + 1;
						qx.push(tx);
						qy.push(ty);
					}
				}
				else {
						if (visit[ty][tx][0] > visit[nowy][nowx][0] + 1) {
							visit[ty][tx][0] = visit[nowy][nowx][0] + 1;
							qx.push(tx);
							qy.push(ty);
						}
						if (visit[ty][tx][1] > visit[nowy][nowx][1] + 1) {
							visit[ty][tx][1] = visit[nowy][nowx][1] + 1;
							qx.push(tx);
							qy.push(ty);
						}
				}
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
	int n, m; scanf("%d %d", &n, &m);
	for ( i = 1; i <= n; i++) {
		for ( j = 1; j <= m; j++) {
			scanf("%1d", &arr[i][j]);
			visit[i][j][0] = INF;
			visit[i][j][1] = INF;
		}
		
	}
	bfs(n, m);
	int ans = min(visit[n][m][0], visit[n][m][1]);
	if (ans == INF) ans = -1;
	printf("%d", ans);
	return 0;
}