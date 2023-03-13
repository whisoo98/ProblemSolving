#include <stdio.h>
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <functional>
#include <stdlib.h>
#include <string>
#include <queue>
#include <stack>
#include <map>


using namespace std;

/*struct type_name {

}srt;*/

//vector <type> vec;
//stack <type> stk;
//queue <type> q;
//string str;
//map <key_type,value_type> m;
int bat[55][55];
int n, m,k;
int arr[55][55];
int warm;
bool ok(int x, int y) {
	if (x<0 || x>=m || y<0 || y>=n || arr[x][y] || !bat[x][y]) return 0;
	return 1;
}
int xx[4] = { 0,1,0,-1 };
int yy[4] = { 1,0,-1,0 };
void dfs(int x, int y) {
	arr[x][y] = 1;
	for (int i = 0; i < 4; i++) {
		if (ok(x + xx[i], y + yy[i])) {
			dfs(x + xx[i], y + yy[i]);
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int i, j;//for문변수-->가끔식 long으로
	int T;
	scanf("%d", &T);
	while (T--) {
		warm = 0;
		scanf("%d %d %d", &m, &n, &k);
		for (i = 0; i < k; i++) {
			int x, y;
			scanf("%d %d", &x, &y);
			bat[x][y] = 1;
		}
		for (i = 0; i < m; i++) {
			for (j = 0; j < n; j++) {
				if (!arr[i][j] && bat[i][j]) {
					warm++;
					dfs(i, j);
				}
			}
		}
		printf("%d\n", warm);
		for (i = 0; i <= m; i++) {
			for (j = 0; j <= n; j++) {
				arr[i][j] = 0;
				bat[i][j] = 0;
			}
		}
	}
	return 0;
}