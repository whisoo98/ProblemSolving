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
queue <int> qx;
queue <int>qy;
queue<int>qz;

//string str;
//map <key_type,value_type> m;
int day;
int xx[6] = { 1,0,0,-1,0,0 };
int yy[6] = { 0,1,0,0,-1,0 };
int zz[6] = { 0,0,1,0,0,-1 };
int x, y, z;
int visit[105][105][105];
int tomato[105][105][105];
bool ok(int i, int j, int k) {
	if (i < 0 || i >= x || j < 0 || j >= y || k < 0 || k >=z || visit[i][j][k] || (tomato[i][j][k] != 0)) return 0;
	else return 1;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int i, j, k;//for문변수-->가끔식 long으로
	scanf("%d %d %d", &x, &y, &z);
	for (k = 0; k < z; k++) {
		for (j = 0; j < y; j++) {
			for (i = 0; i < x; i++) {
				scanf("%d", &tomato[i][j][k]);
			}
		}
	}

	//	day = 1;
	for (k = 0; k < z; k++) {
		for (j = 0; j < y; j++) {
			for (i = 0; i < x; i++) {
				if (tomato[i][j][k]>0) {
					qx.push(i);
					qy.push(j);
					qz.push(k);
					visit[i][j][z] = 1;

				}
			}
		}
	}

	while (!(qx.empty())) {

		int X = qx.front();
		int Y = qy.front();
		int Z = qz.front();
		qx.pop();
		qy.pop();
		qz.pop();
		visit[X][Y][Z] = 1;
		for (i = 0; i < 6; i++) {
			if (ok(X + xx[i], Y + yy[i], Z + zz[i])) {
				qx.push(X + xx[i]);
				qy.push(Y + yy[i]);
				qz.push(Z + zz[i]);
				tomato[X + xx[i]][Y + yy[i]][Z + zz[i]] = tomato[X][Y][Z] + 1;
			}
		}
	}
	int M = -1;
	for (k = 0; k < z; k++) {
		for (j = 0; j < y; j++) {
			for (i = 0; i < x; i++) {
					if (tomato[i][j][k] == 0) {
						printf("-1");
						return 0;
					}
					M = max(M, tomato[i][j][k]);
			}
		}
	}
	if (!M) {
		printf("0");
		return 0;
	}
	printf("%d", M - 1);
	return 0;
}