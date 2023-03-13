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
#define N 305
#define ll long long
#define endl "\n"
#define MID(a,b) (a+b)/2

using namespace std;

int iceberg[N][N];
bool visit[N][N][2];
int dy[] = { 0,0,1,-1 };
int dx[] = { 1,-1,0,0 };

bool ok(int ty, int tx, int y, int x) {
	if (ty<1 || ty>y || tx<1 || tx>x || iceberg[ty][tx] == 0) return false;
	return true;
}


void melt(int y, int x,int year) {
	int temp[N][N];
	for (int i = 2; i <= y-1; i++) {
		for (int j = 2; j <= x-1; j++) {
			int cnt = 0;
			for (int k = 0; k < 4; k++) {
				int ty = i + dy[k];
				int tx = j + dx[k];
				if (iceberg[ty][tx] == 0) cnt++;
			}
			temp[i][j] = cnt;
		}
	}
	for (int i = 2; i <= y - 1; i++) {
		for (int j = 2; j <= x - 1; j++) {
			iceberg[i][j] -= temp[i][j];
			if (iceberg[i][j] < 0) iceberg[i][j] = 0;

			visit[i][j][year] = false;
		}
	}
}

void bfs(int ty, int tx, int y,int x, int year) {
	queue<int> qx;
	queue<int> qy;
	qx.push(tx);
	qy.push(ty);
	visit[ty][tx][year] = true;
	while (qx.size()) {
		int nowy = qy.front(); qy.pop();
		int nowx = qx.front(); qx.pop();
		for (int k = 0; k < 4; k++) {
			int ty = nowy + dy[k];
			int tx = nowx + dx[k];
			if (ok(ty, tx, y, x) && !visit[ty][tx][year]) {
				visit[ty][tx][year] = true;
				qx.push(tx);
				qy.push(ty);
			}
		}
	}
}
int preBfs(int y, int x,int year) {
	
	int cnt = 0;
	for (int i = 2; i <= y - 1; i++) {
		for (int j = 2; j <= x - 1; j++) {
			if (iceberg[i][j] > 0 && !visit[i][j][year]) {
				bfs(i, j, y, x, year);
				cnt++;
			}
		}
	}
	return cnt;
}

void Solution(int y, int x) {
	int year = -1;
	int cnt;
	while (1) {
		year++;
		cnt = preBfs(y, x,year%2);
		if (cnt >= 2 || cnt == 0) {
			break;
		}
		melt(y, x,year%2);
	}
	if (cnt >= 2) {
		cout << year << endl;
	}
	else {
		cout << 0 << endl;
	}
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
			cin >> iceberg[i][j];
		}
	}
	Solution(y, x);
	return 0;
}