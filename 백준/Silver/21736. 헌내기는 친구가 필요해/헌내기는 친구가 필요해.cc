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
#define N 605
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
	if (ty < 1 || ty > y || tx< 1 || tx> x || arr[ty][tx] == 'X') return false;
	return true;
}

int bfs(int y, int x, int sty, int stx) {
	queue<pair<int, int>> q;
	int meet = 0;
	q.push({ sty,stx });
	visit[sty][stx] = 0;
	while (q.size()) {
		int nowy = q.front().first;
		int nowx = q.front().second;
		q.pop();
		for (int dir = 0; dir < 4; dir++) {
			int ty = nowy + dy[dir];
			int tx = nowx + dx[dir];
			if (isOk(ty, tx, y, x) && visit[ty][tx] > visit[nowy][nowx] + 1) {
				visit[ty][tx] = visit[nowy][nowx] + 1;
				if (arr[ty][tx] == 'P') meet++;
				q.push({ ty,tx });
			}
		}
	}
	return meet;
}

void Solution(int y, int x, int sty, int stx) {
	int ans = bfs(y, x, sty, stx);
	if (ans == 0) {
		cout << "TT" << endl;
	}
	else {
		cout << ans << endl;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, j; //for문 변수 -> longlong필요한지 확인
	int y, x; cin >> y >> x;
	int sty, stx;
	for (int i = 0; i < y; i++) {
		string s; cin >> s;
		for (int j = 0; j < x; j++) {
			visit[i + 1][j + 1] = INF;
			arr[i + 1][j + 1] = s[j];
			if (arr[i + 1][j + 1] == 'I') {
				sty = i + 1;
				stx = j + 1;
			}
		}
	}
	Solution(y, x,sty,stx);
	return 0;
}