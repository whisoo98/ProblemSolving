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
int z, y, x;
char building[35][35][35];
int visit[35][35][35];
bool ok(int tz, int ty, int tx) {
	if (tz<0 || tz>=z || tx<0 || tx>=x || ty<0 || ty>=y || building[tz][ty][tx]=='#') return false;
	return true;
}
queue<int>qz, qy, qx;
int xx[] = { 1,0,0,-1,0,0 };
int yy[] = { 0,1,0,0,-1,0 };
int zz[] = { 0,0,1,0,0,-1 };
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int i, j;//for문변수-->가끔식 long으로
	while (1) {
		scanf("%d %d %d", &z, &y, &x);
		if (!(z + x + y)) break;
		int startz, starty, startx, endz, endy, endx;
		for (int k = 0; k < z; k++) {
			for (i = 0; i < y; i++) {

				scanf("%s", building[k][i]);
				for (j = 0; j < x; j++) {
					visit[k][i][j] = 987654321;
					if (building[k][i][j] == 'S') {
						//startx = j; starty = i; startz = k;
						qx.push(j); qy.push(i); qz.push(k);
						visit[k][i][j] = 0;
						//cout << j << " " << i << " " << k << endl;
					}
					else if (building[k][i][j] == 'E') {
						endx = j; endy = i; endz = k;
						//cout << j << " " << i << " " << k << endl;
					}
				}
			}
		}

		while (!qx.empty()) {
			int tz = qz.front(), ty = qy.front(), tx = qx.front();
			qx.pop(); qy.pop(), qz.pop();
			for (i = 0; i < 6; i++) {
				if (ok(tz + zz[i], ty + yy[i], tx + xx[i]) && visit[tz + zz[i]][ty + yy[i]][tx + xx[i]] > visit[tz][ty][tx] + 1) {
					visit[tz + zz[i]][ty + yy[i]][tx + xx[i]] = visit[tz][ty][tx] + 1;
					qx.push(tx + xx[i]); qy.push(ty + yy[i]); qz.push(tz + zz[i]);
				}
			}
		}

		if (visit[endz][endy][endx] == 987654321) printf("Trapped!\n");
		else printf("Escaped in %d minute(s).\n", visit[endz][endy][endx]);
		for (int k = 0; k < z; k++) {
			for (i = 0; i < y; i++) {
				for (j = 0; j < x; j++) {
					building[k][i][j] = '\0';
					visit[k][i][j] = 987654321;
				}
			}
		}

	}
	return 0;
}