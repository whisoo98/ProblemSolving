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

using namespace std;


int arr[N][N];
int visit[N][N];

int dy[] = { 0,0,1,-1 };
int dx[] = { 1,-1,0,0 };

bool isOk(int ty, int tx, int y, int x) {
	if (ty<1 || ty> y || tx< 1 || tx> x || arr[ty][tx]) return false;
	return true;
}

string percolateCurrent(int y, int x) {
	queue<pair<int, int>> q;
	for (int i = 1; i <= x; i++) {
		if (arr[1][i] == 0) {
			visit[1][i] = 1;
			q.push({ 1,i });
		}
	}

	while (q.size()) {
		int nowy = q.front().first;
		int nowx = q.front().second;
		q.pop();
		for (int dir = 0; dir < 4; dir++) {
			int ty = nowy + dy[dir];
			int tx = nowx + dx[dir];
			if (isOk(ty, tx,y, x) && visit[ty][tx] == 0) {
				q.push({ ty,tx });
				visit[ty][tx] = 1;
			}
		}
	}

	for (int i = 1; i <= x; i++) {
		if (visit[y][i]) {
			return "YES";
		}
	}
	return "NO";
}

void Solution(int y, int x) {
	string ans = percolateCurrent(y, x);
	cout << ans << endl;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, j; //for문 변수 -> longlong필요한지 확인
	int y, x; cin >> y >> x;
	for (int i = 1; i <= y; i++) {
		string s; cin >> s;
		for (int j = 1; j <= x; j++) {
			arr[i][j] = s[j - 1] - '0';
		}
	}

	Solution(y, x);
	return 0;
}