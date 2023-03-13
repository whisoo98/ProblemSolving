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
#define N 55
using namespace std;

char arr[N][N];
int visit[N*N][N][N];
int cnt;
int m = -1;
int y, x;
bool ok(int ty, int tx) {
	if (ty < 1 || ty > y || tx<1 || tx>x || arr[ty][tx] == 'W') return false;
	return true;
}
int dy[] = { 0,0,1,-1 };
int dx[] = { 1,-1,0,0 };
void bfs(int ty, int tx, int num) {
	visit[num][ty][tx] = 1;
	queue<pair<int, int>>q;
	q.push({ ty,tx });
	while (!q.empty()) {
		int yy = q.front().first;
		int xx = q.front().second;
		int now = visit[num][yy][xx];
		q.pop();
		for (int i = 0; i < 4; i++) {
			int Y = yy + dy[i];
			int X = xx + dx[i];
			if (ok(Y, X) && visit[num][Y][X] > now + 1) {
				visit[num][Y][X] = now + 1;
				q.push({ Y,X });
				m = max(m, now + 1);
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
	//scanf("%d %d", &y, &x);
	cin >> y >> x;
	for (i = 1; i <= y; i++) {
		string s; cin >> s;
		for (j = 1; j <= x; j++) {
			arr[i][j] = s[j - 1];
		}
	}
	for (int k = 1; k <= 2505; k++) {
		for (i = 1; i <= y; i++) {
			for (j = 1; j <= x; j++) {
				visit[k][i][j] = 987654321;
			}
		}
	}
	for (i = 1; i <= y; i++) {
		for (j = 1; j <= x; j++) {
			cnt++;
			if (arr[i][j] == 'L') {
				bfs(i, j, cnt);
			}
		}
	}
	cout << m - 1;
	return 0;
}