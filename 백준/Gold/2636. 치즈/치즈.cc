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
#define ll long long
#define endl "\n"
#define MID(a,b) (a+b)/2
#define AIR 0
#define CHEESE 1
#define NONAIR 2
#define INF 987654321
using namespace std;

int board[N][N];
int melt[N][N];
int y, x; 

int dy[] = { 0,0,1,-1 };
int dx[] = { 1,-1,0,0 };

bool isOk(int ty, int tx) {
	if (ty < 1 || ty > y || tx <1 || tx >x) return false;
	return true;
}

int meltCheese() {
	int melted_cheese = 0;;
	// using floodfill
	queue<pair<int, int>> q;
	q.push({ 1, 1 });
	melt[1][1] = -1;
	while(q.size()){
		int nowy = q.front().first;
		int nowx = q.front().second;
		q.pop();
		for (int dir = 0; dir < 4; dir++) {
			int ty = nowy + dy[dir];
			int tx = nowx + dx[dir];
			if (isOk(ty, tx) && !melt[ty][tx]) {
				if (board[ty][tx] == CHEESE) {
					melt[ty][tx] = CHEESE;
				}
				else { // AIR
					q.push({ ty,tx });
					melt[ty][tx] = -1;
				}
			}
		}
	}

	for (int i = 1; i <= y; i++) {
		for (int j = 1; j <= x; j++) {
			if (melt[i][j] == CHEESE) {
				board[i][j] = 0;
				melted_cheese++;
			}
			melt[i][j] = 0;
		}
	}
	return melted_cheese;
}

void Solution() {
	int melt_cheese = 0;
	int melting_time = 0;
	while (int is_melt = meltCheese()) {
		melting_time++;
		melt_cheese = is_melt;
	}
	cout << melting_time << endl;
	cout << melt_cheese << endl;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, j; //for문 변수 -> longlong필요한지 확인
	cin >> y >> x;
	for (int i = 1; i <= y; i++) {
		for (int j = 1; j <= x; j++) {
			cin >> board[i][j];
		}
	}
	Solution();
	return 0;
}