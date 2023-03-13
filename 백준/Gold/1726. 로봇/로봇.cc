#include <cstdio>
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
#include <climits>
#include <cstring>


using namespace std;

/*struct type_name {

}srt;*/

//vector <type> vec;
//stack <type> stk;
//queue <type> q;
//string str;
//map <key_type,value_type> m;

int y, x;
vector<int>edge[105];
int arr[105][105];
int visit[5][105][105];

int ed_y, ed_x, ed_dir;
int st_y, st_x, st_dir;

int xx[] = { 0,1,0,-1 };
int yy[] = { 1,0,-1,0 };
bool ok(int ty, int tx) {
	if (ty<1 || ty>y || tx<1 || tx>x || arr[ty][tx]) return false;
	return true;
}

//return 값의 유무에 따라 void or int 
void dfs(int ty, int tx, int dir) {
	if (ty == ed_y && tx == ed_x && dir == ed_dir) {
		return;
	}
	if (visit[dir][ty][tx] > visit[ed_dir][ed_y][ed_x]) return;

	if (dir == 1) {
		if (ok(ty, tx + 3) && ok(ty, tx + 2) && ok(ty, tx + 1) && visit[dir][ty][tx + 3] > visit[dir][ty][tx] + 1) {
			visit[dir][ty][tx + 3] = visit[dir][ty][tx] + 1;
			dfs(ty, tx + 3, dir);
		}
		if (ok(ty, tx + 2) && ok(ty, tx + 1) && visit[dir][ty][tx + 2] > visit[dir][ty][tx] + 1) {
			visit[dir][ty][tx + 2] = visit[dir][ty][tx] + 1;
			dfs(ty, tx + 2, dir);
		}
		if (ok(ty, tx + 1) && visit[dir][ty][tx + 1] > visit[dir][ty][tx] + 1) {
			visit[dir][ty][tx + 1] = visit[dir][ty][tx] + 1;
			dfs(ty, tx + 1, dir);
		}
		if (visit[3][ty][tx] > visit[dir][ty][tx] + 1) {
			visit[3][ty][tx] = visit[dir][ty][tx] + 1;
			dfs(ty, tx, 3);
		}
		if (visit[4][ty][tx] > visit[dir][ty][tx] + 1) {
			visit[4][ty][tx] = visit[dir][ty][tx] + 1;
			dfs(ty, tx, 4);
		}
	}
	else if (dir == 2) {
		if (ok(ty, tx - 3) && ok(ty, tx - 2) && ok(ty, tx - 1) && visit[dir][ty][tx - 3] > visit[dir][ty][tx] + 1) {
			visit[dir][ty][tx - 3] = visit[dir][ty][tx] + 1;
			dfs(ty, tx - 3, dir);
		}
		if (ok(ty, tx - 2) && ok(ty, tx - 1) && visit[dir][ty][tx - 2] > visit[dir][ty][tx] + 1) {
			visit[dir][ty][tx - 2] = visit[dir][ty][tx] + 1;
			dfs(ty, tx - 2, dir);
		}
		if (ok(ty, tx - 1) && visit[dir][ty][tx - 1] > visit[dir][ty][tx] + 1) {
			visit[dir][ty][tx - 1] = visit[dir][ty][tx] + 1;
			dfs(ty, tx - 1, dir);
		}
		if (visit[3][ty][tx] > visit[dir][ty][tx] + 1) {
			visit[3][ty][tx] = visit[dir][ty][tx] + 1;
			dfs(ty, tx, 3);
		}
		if (visit[4][ty][tx] > visit[dir][ty][tx] + 1) {
			visit[4][ty][tx] = visit[dir][ty][tx] + 1;
			dfs(ty, tx, 4);
		}
	}
	else if (dir == 3) {
		if (ok(ty + 3, tx) && ok(ty + 2, tx) && ok(ty + 1, tx) && visit[dir][ty + 3][tx] > visit[dir][ty][tx] + 1) {
			visit[dir][ty + 3][tx] = visit[dir][ty][tx] + 1;
			dfs(ty + 3, tx, dir);
		}
		if (ok(ty + 2, tx) && ok(ty + 1, tx) && visit[dir][ty + 2][tx] > visit[dir][ty][tx] + 1) {
			visit[dir][ty + 2][tx] = visit[dir][ty][tx] + 1;
			dfs(ty + 2, tx, dir);
		}
		if (ok(ty + 1, tx) && visit[dir][ty + 1][tx] > visit[dir][ty][tx] + 1) {
			visit[dir][ty + 1][tx] = visit[dir][ty][tx] + 1;
			dfs(ty + 1, tx, dir);
		}
		if (visit[1][ty][tx] > visit[dir][ty][tx] + 1) {
			visit[1][ty][tx] = visit[dir][ty][tx] + 1;
			dfs(ty, tx, 1);
		}
		if (visit[2][ty][tx] > visit[dir][ty][tx] + 1) {
			visit[2][ty][tx] = visit[dir][ty][tx] + 1;
			dfs(ty, tx, 2);
		}
	}
	else if (dir == 4) {
		if (ok(ty - 3, tx) && ok(ty - 2, tx) && ok(ty - 1, tx) && visit[dir][ty - 3][tx] > visit[dir][ty][tx] + 1) {
			visit[dir][ty - 3][tx] = visit[dir][ty][tx] + 1;
			dfs(ty - 3, tx, dir);
		}
		if (ok(ty - 2, tx) && ok(ty - 1, tx) && visit[dir][ty - 2][tx] > visit[dir][ty][tx] + 1) {
			visit[dir][ty - 2][tx] = visit[dir][ty][tx] + 1;
			dfs(ty - 2, tx, dir);
		}
		if (ok(ty - 1, tx) && visit[dir][ty - 1][tx] > visit[dir][ty][tx] + 1) {
			visit[dir][ty - 1][tx] = visit[dir][ty][tx] + 1;
			dfs(ty - 1, tx, dir);
		}
		if (visit[1][ty][tx] > visit[dir][ty][tx] + 1) {
			visit[1][ty][tx] = visit[dir][ty][tx] + 1;
			dfs(ty, tx, 1);
		}
		if (visit[2][ty][tx] > visit[dir][ty][tx] + 1) {
			visit[2][ty][tx] = visit[dir][ty][tx] + 1;
			dfs(ty, tx, 2);
		}
	}
}

// from now cut into main

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int i, j;//for문변수-->가끔식 long으로
	
	scanf("%d %d", &y, &x);
	for (i = 1; i <= y; i++) {
		for (j = 1; j <= x; j++) {//1 동 2 서 3 남 4북
			scanf("%d", &arr[i][j]);
			visit[4][i][j] = 987654321;
			visit[1][i][j] = 987654321;
			visit[2][i][j] = 987654321;
			visit[3][i][j] = 987654321;
		}
	}
	scanf("%d %d %d", &st_y, &st_x, &st_dir);
	scanf("%d %d %d", &ed_y, &ed_x, &ed_dir);

	//시작조건 확인!! 
	visit[st_dir][st_y][st_x] = 0;
	dfs(st_y, st_x, st_dir);
	int temp = 997654321;
	
	printf("%d\n", visit[ed_dir][ed_y][ed_x]);
	//if(temp==987654321) 
	//for(i=0;i<n;i++) {}
	//for(i=0;i<n;i++) { for(j=0;j<n;j++) { } }

	return 0;
}