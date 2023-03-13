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
#define N 255
using namespace std;

char arr[N][N];
int visit[N][N];
int y, x;
bool ok(int ty, int tx) {
	if (ty < 1 || ty > y || tx<1 || tx>x || arr[ty][tx]=='#') return false;
	return true;
}
int dy[] = { 0,0,1,-1 };
int dx[] = { 1,-1,0,0 };
int sheep, wolf;

void dfs(int ty, int tx, int* o, int* v) {
	visit[ty][tx] = 1;
	for (int i = 0; i < 4; i++) {
		int yy = ty + dy[i];
		int xx = tx + dx[i];
		if (ok(yy, xx) && visit[yy][xx] != 1) {
			if (arr[yy][xx] == '.') {
				dfs(yy, xx, o, v);
			}
			else if (arr[yy][xx] == 'o') {
				(*o)++;
				dfs(yy, xx, o, v);
			}
			else if (arr[yy][xx] == 'v') {
				(*v)++;
				dfs(yy, xx, o, v);
			}
		}
	}
	//cout << *o << " " << *v << endl;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, j; //for문 변수 -> longlong필요한지 확인
	cin >> y >> x;
	for (i = 1; i <= y; i++) {
		string s; cin >> s;
		for (j = 1; j <= x; j++) {
			arr[i][j] = s[j - 1];
		}
	}
	for (i = 1; i <= y; i++) {
		for (j = 1; j <= x; j++) {
			if (arr[i][j] == 'v' && visit[i][j] == 0) {
				int o = 0, v = 1;
				dfs(i, j, &o, &v);
				if (o > v) sheep += o;
				else wolf += v;
			}
			else if (arr[i][j] == 'o' && visit[i][j] == 0) {
				int o = 1, v = 0;
				dfs(i, j, &o, &v);
				if (o > v) sheep += o;
				else wolf += v;
			}
		}
	}
	cout << sheep << " " << wolf;
	return 0;
}