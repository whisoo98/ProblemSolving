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
#define INF 987654321
using namespace std;

int arr[N][N];
int visit[N][N];
int dy[] = { 0,0,1,-1 };
int dx[] = { 1,-1,0,0 };

bool isOk(int ty, int tx, int y, int x) {
	if (ty<1 || ty> y || tx<1 || tx>x || arr[ty][tx] == 0) return false;
	return true;
}

void bfs(int y, int x, int sty, int stx) {
	queue<int> qy;
	queue<int> qx;
	qy.push(sty);
	qx.push(stx);
	while (qy.size()) {
		int nowy = qy.front();
		int nowx = qx.front();
		qy.pop();
		qx.pop();
		for (int dir = 0; dir < 4; dir++) {
			int ty = nowy + dy[dir];
			int tx = nowx + dx[dir];
			if (isOk(ty, tx, y, x) && visit[ty][tx] > visit[nowy][nowx] + 1) {
				visit[ty][tx] = visit[nowy][nowx] + 1;
				qy.push(ty);
				qx.push(tx);
			}
		}
	}
}

void Solution(int y, int x, int sty, int stx) {
	bfs(y, x, sty, stx);

	for (int i = 1; i <= y; i++) {
		for (int j = 1; j <= x; j++) {
			if (visit[i][j] == INF) {
				if (arr[i][j] == 1) {

					cout << -1 << " ";
				}
				else {
					cout << 0 << " ";
				}
			}
			else {
				cout << visit[i][j] << " ";
			}
		}
		cout << endl;
	}
	cout << endl;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, j; //for문 변수 -> longlong필요한지 확인
	int y, x; cin >> y >> x;
	int sty, stx;
	for (int i = 1; i <= y; i++) {
		for (int j = 1; j <= x; j++) {
			visit[i][j] = INF;
			cin >> arr[i][j];
			if (arr[i][j] == 2) {
				sty = i;
				stx =j;
				visit[i][j] = 0;
			}
		}
	}

	Solution(y, x, sty, stx);
	return 0;
}