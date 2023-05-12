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
#define N 15
#define ll long long
#define endl "\n"
#define MID(a,b) (a+b)/2

using namespace std;

int board[N][N];
int drawn[N][N];
int y, x;
int dy[] = { 0,0,1,-1 };
int dx[] = { 1,-1,0,0 };
bool isOk(int ty, int tx) {
	if (ty<0 || ty>y+1 || tx<0 || tx>x+1) return false;
	return true;
}

void isDrawning() {
	for (int i = 1; i <= y; i++) {
		for (int j = 1; j <= x; j++) {
			if (board[i][j]) {
				int cnt = 0;
				for (int k = 0; k < 4; k++) {
					int ty = i + dy[k];
					int tx = j + dx[k];
					if (isOk(ty, tx) && !board[ty][tx]) {
						cnt++;
					}
				}
				if (cnt >= 3) {
					drawn[i][j] = 1;
				}
			}
			
		}
	}
}

void Drawn() {
	for (int i = 1; i <= y; i++) {
		for (int j = 1; j <= x; j++) {
			if (drawn[i][j]) {
				board[i][j] = 0;
			}
		}
	}
}

void drawMap() {
	int left = 987654321, right = 0, up = 987654321, down = 0;

	for (int i = 1; i <= y; i++) {
		for (int j = 1; j <= x; j++) {
			if (board[i][j]) {
				left = min(left, j);
				up = min(up, i);
				right = max(right, j);
				down = max(down, i);
			}
		}
	}
	for (int i = up; i <= down; i++) {
		for (int j = left; j <= right; j++) {
			if (board[i][j] == 0) {
				cout << ".";
			}
			else {
				cout << "X";
			}
		}
		cout << endl;
	}
}
void Solution() {
	isDrawning();
	Drawn();
	drawMap();
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, j; //for문 변수 -> longlong필요한지 확인
	cin >> y >> x;
	for (int i = 1; i <= y; i++) {
		string s; cin >> s;
		for (int j = 0; j < x; j++) {
			if (s[j] == 'X') {
				board[i][j + 1] = 1;
			}
		}
	}
	Solution();

	return 0;
}