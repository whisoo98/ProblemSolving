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
#define ll long long
#define endl "\n"
#define MID(a,b) (a+b)/2

using namespace std;

int board[N][N];
int visit[N][N];
int dy[] = { 0,0,1,-1 };
int dx[] = { 1,-1 ,0,0 };

bool isOk(int ty, int tx, int y, int x) {
	if (ty<1 || ty > y || tx<1 || tx > x) return false;
	return true;
}


int floodFill(int nowy, int nowx, int y, int x) {
	int area = 0;
	queue<pair<int, int>> q;
	q.push({ nowy, nowx });
	visit[nowy][nowx] = 1;
	while (q.size()) {
		int nowy = q.front().first;
		int nowx = q.front().second;
		q.pop();
		area++;
		for (int dir = 0; dir < 4; dir++) {
			int ty = nowy + dy[dir];
			int tx = nowx + dx[dir];
			if (isOk(ty, tx, y, x) && board[ty][tx] && !visit[ty][tx]) {
				q.push({ ty,tx });
				visit[ty][tx] = 1;
			}
		}
	}
	return area;
}

void Solution(int y, int x) {
	int cnt_drawing = 0;
	int max_area = 0;
	for (int i = 1; i <= y; i++) {
		for (int j = 1; j <= x; j++) {
			if (!visit[i][j] && board[i][j]) {
				int area = floodFill(i, j, y, x);
				cnt_drawing++;
				max_area = max(area, max_area);
			}
		}
	}
	cout << cnt_drawing << endl << max_area << endl;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, j; //for문 변수 -> longlong필요한지 확인
	int y, x; cin >> y >> x;
	for (int i = 1; i <= y; i++) {
		for (int j = 1; j <= x; j++) {
			cin >> board[i][j];
		}
	}
	Solution(y, x);
	return 0;
}