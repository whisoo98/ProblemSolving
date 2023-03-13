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
int tomato[1005][1005];
bool visit[1005][1005];
queue<int> qx, qy;
int x, y;

int xx[] = { 0,1,0,-1 };
int yy[] = { 1,0,-1,0 };
bool ok(int dy, int dx) {
	if (dx < 1 || dx>x || dy<1 || dy>y || tomato[dy][dx] != 0 || visit[dy][dx]) return false;
	return true;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int i, j;//for문변수-->가끔식 long으로
	cin >> x >> y;
	for (i = 1; i <= y; i++) {
		for (j = 1; j <= x; j++) {
			cin >> tomato[i][j];
			
			if (tomato[i][j]==1) {
				qx.push(j); qy.push(i);
				//cout << tomato[x][y]<<endl;
			}
		}
	}

	while (!qx.empty() && !qy.empty()) {
		int tx = qx.front(), ty = qy.front();
		qx.pop(); qy.pop();
	//	cout << tx << " " << ty << endl;
		visit[ty][tx] = 1;
		for (i = 0; i < 4; i++) {
			if (ok(ty + yy[i], tx + xx[i])) {
				tomato[ty + yy[i]][tx + xx[i]] = tomato[ty][tx] + 1;
				//visit[tx + xx[i]][ty + yy[i]] = 1;
				qx.push(tx + xx[i]); qy.push(ty + yy[i]);
			}
		}
	}

	int m = -2;
	for (i = 1; i <= y; i++) {
		for (j = 1; j <= x; j++) {
			if (tomato[i][j] == 0) {
				printf("-1");
				return 0;
			}
		//	cout << tomato[i][j]<<" ";
			m = max(m, tomato[i][j]);
		}
	//	cout << endl;
	}
	if (m == -1) printf("-1");
	else printf("%d", m - 1);
	return 0;
}