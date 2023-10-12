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
//#include <map>
#include <vector>
#include <set>
#include <sstream>
#include <ctime>
#include <climits>
#include <tuple>
#define N 25
#define ll long long
#define endl "\n"
#define MID(a,b) (a+b)/2
#define NORTH 0
#define WEST 1
#define SOUTH 2
#define EAST 3
using namespace std;
int saikoro_dy[] = { -1,0,1,0 };
int saikoro_dx[] = { 0,-1,0,1 };

int saikoro_zenkai[7][4] = {
	{'n','w','s','e'},
	{2,4,5,3}, // bottom == 1
	{6,4,1,3}, // bottom == 2
	{2,1,5,6}, // bottom == 3
	{2,6,5,1}, // bottom == 4
	{1,4,6,3}, // bottom == 5
	{5,4,2,3}, // bottom == 6
};
// north, west, south, east ,bottom, top, y, x, dir;
tuple<int, int, int, int, int, int, int, int, int> saikoro; 

int map[N][N];
int score_map[N][N];
int isSaikoroOk(int ty, int tx, int y, int x) {
	if (ty<1 || ty>y || tx < 1 || tx>x) return false;
	return true;
}

int visit[N][N];

void preProcess(int map_y, int map_x) {
	for (int i = 1; i <= map_y; i++) {
		for (int j = 1; j <= map_x; j++) {
			memset(visit, 0, sizeof(visit));
			int value = map[i][j];
			int cnt = 1;
			queue<int> qy;
			queue<int> qx;
			qy.push(i);
			qx.push(j);
			visit[i][j] = 1;
			while (qy.size()) {
				int now_y = qy.front(); qy.pop();
				int now_x = qx.front(); qx.pop();
				for (int k = 0; k < 4; k++) {
					int ty = now_y + saikoro_dy[k];
					int tx = now_x + saikoro_dx[k];
					if (isSaikoroOk(ty, tx, map_y, map_x) && map[ty][tx] == value && !visit[ty][tx]) {
						visit[ty][tx] = 1;
						cnt++;
						qy.push(ty);
						qx.push(tx);
					}
				}
			}
			score_map[i][j] = value * cnt;
		}
	}
}	

void saveSaikoro(int saikoro_y, int saikoro_x, int dir) {
	int saikoro_north = get<0>(saikoro);
	int saikoro_west = get<1>(saikoro);
	int saikoro_south = get<2>(saikoro);
	int saikoro_east = get<3>(saikoro);
	int saikoro_bottom = get<4>(saikoro);
	int saikoro_top = get<5>(saikoro);

	int temp = saikoro_bottom;
	if (dir == NORTH) {
		saikoro_bottom = saikoro_north;
		saikoro_north = saikoro_top;
		saikoro_top = saikoro_south;
		saikoro_south = temp;
	}
	else if (dir == SOUTH) {
		saikoro_bottom = saikoro_south;
		saikoro_south = saikoro_top;
		saikoro_top = saikoro_north;
		saikoro_north = temp;
	}
	else if (dir == WEST) {
		saikoro_bottom = saikoro_west;
		saikoro_west = saikoro_top;
		saikoro_top = saikoro_east;
		saikoro_east = temp;
	}
	else if (dir == EAST) {
		saikoro_bottom = saikoro_east;
		saikoro_east = saikoro_top;
		saikoro_top = saikoro_west;
		saikoro_west = temp;
	}
	saikoro = { saikoro_north, saikoro_west, saikoro_south, saikoro_east, saikoro_bottom, saikoro_top, saikoro_y, saikoro_x, dir };
}

void moveSaikoro(int map_y,int map_x) {
	int saikoro_north = get<0>(saikoro);
	int saikoro_west = get<1>(saikoro);
	int saikoro_south = get<2>(saikoro);
	int saikoro_east = get<3>(saikoro);
	int saikoro_bottom = get<4>(saikoro);
	int saikoro_top = get<5>(saikoro);
	int saikoro_y = get<6>(saikoro);
	int saikoro_x = get<7>(saikoro);
	int saikoro_dir = get<8>(saikoro);
	
	int ty = saikoro_y + saikoro_dy[saikoro_dir];
	int tx = saikoro_x + saikoro_dx[saikoro_dir];
	if (isSaikoroOk(ty, tx, map_y, map_x)) {
		//saikoro = { ty,tx,saikoro_zenkai[saikoro_bottom][saikoro_dir], saikoro_dir };
		//saveSaikoro(ty, tx, saikoro_dir);
	}
	else {
		saikoro_dir += 2;
		saikoro_dir %= 4;
		ty = saikoro_y + saikoro_dy[saikoro_dir];
		tx = saikoro_x + saikoro_dx[saikoro_dir];
		//saikoro = { ty,tx,saikoro_zenkai[saikoro_bottom][saikoro_dir], saikoro_dir };
		//saveSaikoro(ty, tx, saikoro_dir);
	}
	saveSaikoro(ty, tx, saikoro_dir);
	//saikoro = { saikoro_north, saikoro_west, saikoro_south, saikoro_east, saikoro_bottom, saikoro_top, saikoro_y, saikoro_x, saikoro_dir };
}

int gainScore() {
	int saikoro_y = get<6>(saikoro);
	int saikoro_x = get<7>(saikoro);
	return score_map[saikoro_y][saikoro_x];
}

void decideSaikoroMove() {
	int saikoro_north = get<0>(saikoro);
	int saikoro_west = get<1>(saikoro);
	int saikoro_south = get<2>(saikoro);
	int saikoro_east = get<3>(saikoro);
	int saikoro_bottom = get<4>(saikoro);
	int saikoro_top = get<5>(saikoro);
	int saikoro_y = get<6>(saikoro);
	int saikoro_x = get<7>(saikoro);
	int saikoro_dir = get<8>(saikoro);

	if (saikoro_bottom > map[saikoro_y][saikoro_x]) {
		//cout << "BIG" << endl;
		saikoro_dir--;
		saikoro_dir += 4;
		saikoro_dir %= 4;
	}
	else if (saikoro_bottom < map[saikoro_y][saikoro_x]) {
		//cout << "small" << endl;

		saikoro_dir++;
		saikoro_dir %= 4;
	}
	saikoro = { saikoro_north, saikoro_west, saikoro_south, saikoro_east, saikoro_bottom, saikoro_top, saikoro_y, saikoro_x, saikoro_dir };
	//saveSaikoro(saikoro_y, saikoro_x, saikoro_dir);
}

void debugSaikoro() {
	int saikoro_north = get<0>(saikoro);
	int saikoro_west = get<1>(saikoro);
	int saikoro_south = get<2>(saikoro);
	int saikoro_east = get<3>(saikoro);
	int saikoro_bottom = get<4>(saikoro);
	int saikoro_top = get<5>(saikoro);
	int saikoro_y = get<6>(saikoro);
	int saikoro_x = get<7>(saikoro);
	int saikoro_dir = get<8>(saikoro);
	cout << "---------------------------------------" << endl;
	cout << "  "<< saikoro_south << "  " << endl;
	cout << saikoro_west << " " << saikoro_top << " " << saikoro_east << endl;
	cout << "  " << saikoro_north << "  " << endl;
	cout << "  " << saikoro_bottom << "  " << endl;
	cout << saikoro_y << " " << saikoro_x << " " ;
	if (saikoro_dir == NORTH)
		cout << "NORTH\n";
	if (saikoro_dir == SOUTH)
		cout << "SOUTH\n";
	if (saikoro_dir == WEST)
		cout << "WEST\n";
	if (saikoro_dir == EAST)
		cout << "EAST\n";
	cout << "---------------------------------------" << endl;
}
void Solution(int map_y, int map_x, int move_cnt) {
	int ans = 0;
	saikoro = { 2, 4, 5, 3, 6, 1, 1, 1, EAST };
	preProcess(map_y, map_x);
	//debugSaikoro();

	while (move_cnt--) {
		moveSaikoro(map_y, map_x);
		int gained = gainScore();
		ans += gained;
		decideSaikoroMove();
		//debugSaikoro();
	}
	cout << ans << endl;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, j; //for문 변수 -> longlong필요한지 확인
	int y, x, move_cnt; cin >> y >> x >> move_cnt;
	for (int i = 1; i <= y; i++) {
		for (int j = 1; j <= x; j++) {
			cin >> map[i][j];
		}
	}

	Solution(y, x, move_cnt);
	return 0;
}