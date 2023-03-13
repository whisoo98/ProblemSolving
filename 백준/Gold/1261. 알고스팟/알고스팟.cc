#include <cstdio>
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

using namespace std;

priority_queue<pair<int,pair<int,int>>> q;
bool arr[105][105];
int visit[105][105];
int dp[105][105];
int dy[] = { 0,1,0,-1 };
int dx[] = { 1,0,-1,0 };
int x, y;
bool ok(int ty, int tx) {
	if (ty<1 || ty>y || tx < 1 || tx>x) return false;
	return true;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, j; //for문 변수 -> longlong필요한지 확인
	 scanf("%d %d", &x, &y);
	for (i = 1; i <= y; i++) {
		for (j = 1; j <= x; j++) {
			scanf("%1d", &arr[i][j]);
		}
	}

	q.push({ 0,{1,1} });
	visit[1][1] = 1;
	while (!q.empty()) {
		int count = -q.top().first;
		int nowx = q.top().second.first;
		int nowy = q.top().second.second;
		if (nowx == x && nowy == y) {
			printf("%d\n", count);
			break;
		}
		q.pop();
		for (i = 0; i < 4; i++) {
			int ty = nowy + dy[i];
			int tx = nowx + dx[i];
			if (ok(ty, tx)&&visit[ty][tx]==0) {
				q.push({ -(count + arr[ty][tx]),{tx,ty} });
				visit[ty][tx] = 1;
			}
		}
	}
	return 0;
}