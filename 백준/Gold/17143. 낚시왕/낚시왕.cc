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
#define N 105
#define ll long long
#define endl "\n"
#define MID(a,b) (a+b)/2
#define UP 1
#define DOWN 2
#define RIGHT 3
#define LEFT 4
using namespace std;

int board[N][N];
int dy[] = { 0,-1,1,0,0 };
int dx[] = { 0,0,0,1,-1 };
int fisher;
// y, x, speed, dir, velocity
vector<tuple<int, int, int, int, int>> shark;

bool isOk(int ty, int tx, int y, int x) {
	if (ty<1 || ty > y || tx <1 || tx >x)return false;
	return true;
}


int catchShark(int y, int x, int number_shark) {
	int catched = 0;
	int ret = 0;
	for (int i = 1; i <= y; i++) {
		if (board[i][fisher]) {
			catched = board[i][fisher];
			board[i][fisher] = 0;
			break;
		}
	}

	if (catched) {
		/*int shark_y = get<0>(shark[catched - 1]);
		int shark_x = get<1>(shark[catched - 1]);
		int shark_speed = get<2>(shark[catched - 1]);
		int shark_dir = get<3>(shark[catched - 1]);
		int shark_size = get<4>(shark[catched - 1]);*/
		ret = get<4>(shark[catched - 1]);
		shark[catched - 1] = { 0,0,0,0,-1 };
	}
	return ret;
}

void moveShark(int y, int x, int number_shark) {
	int copy_board[N][N];
	memset(copy_board, 0, sizeof(copy_board));

	for (int i = 0; i < number_shark; i++) {
		int shark_y = get<0>(shark[i]);
		int shark_x = get<1>(shark[i]);
		int shark_speed = get<2>(shark[i]);
		int shark_dir = get<3>(shark[i]);
		int shark_size = get<4>(shark[i]);
		if (shark_size == -1)
			continue;
		int mod_speed = shark_speed;
		switch (shark_dir)
		{
		case UP:
			mod_speed %= 2*(y - 1);
			if ((shark_speed / 2 * (y - 1)) && shark_y == y) {
				shark_dir = DOWN;
			}
			break;
		case DOWN:
			mod_speed %= 2 * (y - 1);
			if ((shark_speed / 2 * (y - 1)) && shark_y == 1) {
				shark_dir = UP;
			}
			break;
		case LEFT:
			mod_speed %= 2*(x - 1);
			if ((shark_speed / 2 * (x - 1)) && shark_x == x) {
				shark_dir = RIGHT;
			}
			break;
		case RIGHT:
			mod_speed %= 2 * (x - 1);
			if ((shark_speed / 2 * (x - 1)) && shark_x == 1) {
				shark_dir = LEFT;
			}
			break;
		default:
			break;
		}
		
		for (int j = 0; j < mod_speed; j++) {
			int ty = shark_y + dy[shark_dir];
			int tx = shark_x + dx[shark_dir];
			if (isOk(ty, tx, y, x)) {
				shark_y = ty;
				shark_x = tx;
			}
			else {
				switch (shark_dir)
				{
				case UP:
					shark_dir = DOWN;
					ty = shark_y + dy[shark_dir];
					tx = shark_x + dx[shark_dir];
					shark_y = ty;
					shark_x = tx;
					break;
				case DOWN:
					shark_dir = UP;
					ty = shark_y + dy[shark_dir];
					tx = shark_x + dx[shark_dir];
					shark_y = ty;
					shark_x = tx;
					break;
				case LEFT:
					shark_dir = RIGHT;
					ty = shark_y + dy[shark_dir];
					tx = shark_x + dx[shark_dir];
					shark_y = ty;
					shark_x = tx;
					break;
				case RIGHT:
					shark_dir = LEFT;
					ty = shark_y + dy[shark_dir];
					tx = shark_x + dx[shark_dir];
					shark_y = ty;
					shark_x = tx;
					break;
				default:
					break;
				}
			}
		}
		if (copy_board[shark_y][shark_x]) {
			int existing_shark = copy_board[shark_y][shark_x];
			int existing_shark_size = get<4>(shark[existing_shark - 1]);
			if (shark_size > existing_shark_size) {
				copy_board[shark_y][shark_x] = i + 1;
				shark[existing_shark - 1] = { 0,0,0,0,-1 };
				shark[i] = { shark_y,shark_x,shark_speed,shark_dir,shark_size };
			}
			else {
				shark[i] = { 0,0,0,0,-1 };
			}
		}
		else {
			copy_board[shark_y][shark_x] = i + 1;
			shark[i] = { shark_y,shark_x,shark_speed,shark_dir,shark_size };
		}
	}

	for (int i = 1; i <= y; i++) {
		for (int j = 1; j <= x; j++) {
			board[i][j] = copy_board[i][j];
		}
	}
}

void Solution(int y, int x, int number_shark) {
	int ans = 0;
	for (int i = 0; i < x; i++) {
		fisher++;
		ans += catchShark(y, x, number_shark);
		moveShark(y, x, number_shark);
	}
	cout << ans << endl;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, j; //for문 변수 -> longlong필요한지 확인
	int y, x, number_shark; cin >> y >> x >> number_shark;
	for (int i = 1; i <= number_shark; i++) {
		int shark_y, shark_x, speed, dir, sz;
		cin >> shark_y >> shark_x >> speed >> dir >> sz;
		shark.push_back({ shark_y,shark_x, speed, dir, sz });
		board[shark_y][shark_x] = i;
	}
	fisher = 0;
	Solution(y, x, number_shark);
	return 0;
}