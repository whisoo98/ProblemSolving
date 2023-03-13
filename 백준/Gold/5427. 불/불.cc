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

int x, y;
char arr[1010][1010];
int visit[1010][1010];
int dx[] = { 0,1,0,-1 };
int dy[] = { 1,0,-1,0 };
bool bound(int ty, int tx) {
	if (ty == 0 || tx == 0 || ty > y || tx > x) return true;
	return false;
}
bool ok(int ty, int tx) {
	if (ty<1 || ty>y || tx<1 || tx>x) return false;
	return true;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, j; //for문 변수 -> longlong필요한지 확인
	int T; cin >> T;
	//경계 - x=0 || y=0 || x=x+1 || y=y+1
	while (T--) {
		cin >> x >> y;
		int cnt = 0;
		queue<pair<int,int>> run;
		queue<pair<int, int>> fire;
		for (i = 0; i <= y + 1; i++) {
			for (j = 0; j <= x + 1; j++) {
				visit[i][j] = 987654321;
			}
		}
		for (i = 0; i < y; i++) {
			string s; cin >> s;
			for (j = 1; j <= x; j++) {
				arr[i + 1][j] = s[j - 1];
				if (arr[i + 1][j] == '*') {
					fire.push({ i + 1,j });
					visit[i + 1][j] = -1;
				}
				else if (arr[i + 1][j] == '@') {
					run.push({ i + 1,j });
					visit[i + 1][j] = 1;
				}
				else if (arr[i + 1][j] == '#') {
					visit[i + 1][j] = -2;
				}
				
			}
		}
		while (!run.empty() && !cnt) {
			int size = run.size();
			for (j = 0; j < size; j++) {
				int nowy = run.front().first;
				int nowx = run.front().second;
				run.pop();
				if (bound(nowy, nowx)) {
					cout << visit[nowy][nowx] - 1 << "\n";
					cnt = 1;
					break;
				}
				for (i = 0; i < 4; i++) {
					int ty = nowy + dy[i];
					int tx = nowx + dx[i];
					if (visit[nowy][nowx]!= -1 && visit[ty][tx] >= 0 && visit[ty][tx] > visit[nowy][nowx] + 1) {
						visit[ty][tx] = visit[nowy][nowx] + 1;
						run.push({ ty,tx });
					}
				}
			}
			size = fire.size();
			for (j = 0; j < size; j++) {
				int nowy = fire.front().first;
				int nowx = fire.front().second;
				fire.pop();
				for (i = 0; i < 4; i++) {
					int ty = nowy + dy[i];
					int tx = nowx + dx[i];
					if (ok(ty, tx) && visit[ty][tx] >= 0) {
						visit[ty][tx] = -1;
						fire.push({ ty,tx });
					}
				}
			}
		}
		if (!cnt) {
			cout << "IMPOSSIBLE\n";
		}
		for (i = 0; i <= y + 1; i++) {
			for (j = 0; j <= x + 1; j++) {
				visit[i][j] = 987654321;
				arr[i][j] = 0;
			}
		}
	}

	return 0;
}