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
#define N 105
using namespace std;

int arr[N][N];
int visit[N][N];
int dy[] = { 0,1,0,-1 };
int dx[] = { 1,0,-1,0 };
int n;
vector<pair<int, int>> point[N*N];
bool ok(int ty, int tx) {
	if (ty < 1 || ty>n || tx<1 || tx>n) return false;
	return true;
}
void dfs(int y, int x, int cnt) {
	visit[y][x] = cnt;
	int chk = 0;
	for (int k = 0; k < 4; k++) {
		int yy = y + dy[k];
		int xx = x + dx[k];
		if (ok(yy, xx) && arr[yy][xx] && visit[yy][xx] == 0) {
			dfs(yy, xx, cnt);
		}
		else if (arr[yy][xx] == 0) {
			chk++;
		}
	}
	if (chk) {
		point[cnt].push_back({ y,x });
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, j; //for문 변수 -> longlong필요한지 확인
	cin >> n;
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++) {
			cin >> arr[i][j];
		}
	}
	int cnt = 0;
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++) {
			if (arr[i][j] && visit[i][j] == 0) {
				cnt++;
				dfs(i, j, cnt);
			}
		}
	}
	for (i = 1; i <= cnt; i++) {
		sort(point[i].begin(), point[i].end());
	}
	int m = 987654321;
	for (i = 1; i <= cnt; i++) {
		int size1 = point[i].size();

		for (j = i + 1; j <= cnt; j++) {
			int size2 = point[j].size();

			for (int k = 0; k < size1; k++) {
				for (int h = 0; h < size2; h++) {
					int ty = abs(point[i][k].first - point[j][h].first);
					int tx = abs(point[i][k].second - point[j][h].second);
					m = min(m, ty + tx - 1);
				}
			}

		}
	}
	cout << m;
	return 0;
}