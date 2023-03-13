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
int n;
int arr[130][130];
int dp[130][130];
//priority_queue<pair<int, int>> q;
bool ok(int y, int x) {
	if (y<1 || y>n || x<1 || x>n) return false;
	return true;
}
int xx[] = { 0,1,0,-1 };
int yy[] = { 1,0,-1,0 };
queue<int>qx;
queue<int>qy;
vector<pair<int, int>>edge;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int i, j;//for문변수-->가끔식 long으로
	int chk = 0;
	while (++chk) {
		 scanf("%d", &n);
		if (n == 0) return 0;
		for (i = 1; i <= n; i++) {
			for (j = 1; j <= n; j++) {
				scanf("%d", &arr[i][j]);
				dp[i][j] = 987654321;
			}
		}
		dp[1][1] = arr[1][1];
		qx.push(1); qy.push(1);
		while (!qx.empty()) {
			int tx = qx.front(); qx.pop();
			int ty = qy.front(); qy.pop();
			for (i = 0; i < 4; i++) {
				if (ok(ty + yy[i], tx + xx[i]) && dp[ty+yy[i]][tx+xx[i]]>dp[ty][tx]+arr[ty+yy[i]][tx+xx[i]]) {
					dp[ty + yy[i]][tx + xx[i]] = dp[ty][tx] + arr[ty + yy[i]][tx + xx[i]];
					qx.push(tx + xx[i]); qy.push(ty + yy[i]);
				}
			}
		}
		printf("Problem %d: %d\n", chk, dp[n][n]);


		for (i = 1; i <= n; i++) {
			for (j = 1; j <= n; j++) {
				arr[i][j] = 0;
				dp[i][j] = 987654321;
			}
		}
	}
	return 0;
}