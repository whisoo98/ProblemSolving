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
#define N 30
#define DIR 4
#define ll long long
#define endl "\n"
#define MID(a,b) (a+b)/2
#define LIM 1000
#define UP 1
#define DOWN 2
#define LEFT 3
#define RIGHT 4
#define DIE 490
using namespace std;

int board[N][N];
int temp_board[N][N];
vector<int> shark_dir[500][DIR];
//queue<tuple<int,int, int, int >> shark; // y, x, dir, number
deque<tuple<int, int, int, int>> shark(500);
int live_shark;
map < pair<int, int>, pair<int,int> > shark_smell; // y, x | shark_num, left_time
int dy[] = { -1, 1,  0, 0 };
int dx[] = {  0, 0, -1, 1 };



bool isOk(int ty, int tx, int y, int x) {
	if (ty<1 || ty>y || tx<1 || tx>x) return false;
	return true;
}

void moveShark(int y, int x, int dir, int shark_num, int n) {
	// no smell => there is no existing shark
	//vector<pair<int, int>> move_candid;
	int move_y=y, move_x=x, move_dir=dir, move = 0;
	for (auto prior_dir : shark_dir[shark_num][dir - 1]) {
		int ty = y + dy[prior_dir - 1];
		int tx = x + dx[prior_dir - 1];
		if (isOk(ty, tx, n, n) && !shark_smell[{ty, tx}].second) {
			//move_candid.push_back({ ty,tx });
			move = 1;
			move_y = ty;
			move_x = tx;
			move_dir = prior_dir;
			break;
		}
	}
	
	// my smell => also there is no existing shark
	if (!move) {
		for (auto prior_dir : shark_dir[shark_num][dir - 1]) {
			int ty = y + dy[prior_dir - 1];
			int tx = x + dx[prior_dir - 1];
			if (isOk(ty, tx, n, n) && shark_smell[{ty, tx}].second && shark_smell[{ty, tx}].first == shark_num) {
				//move_candid.push_back({ ty,tx });
				move = 1;
				move_y = ty;
				move_x = tx;
				move_dir = prior_dir;
				break;
			}
		}
	}

	//temp_board[move_y][move_x] = min(shark_num, temp_board[move_y][move_x]);
	if (shark_num < temp_board[move_y][move_x]) {
		if (temp_board[move_y][move_x] != DIE) {
			shark[temp_board[move_y][move_x]] = { move_y,move_x,move_dir,DIE };
			live_shark--;
		}
		temp_board[move_y][move_x] = shark_num;
		shark[shark_num] = { move_y,move_x,move_dir,shark_num };
	}
	else if(shark_num > temp_board[move_y][move_x]){
		shark[shark_num] = { move_y,move_x,move_dir,DIE };
		live_shark--;
	}
	//cout << move_y << " " << move_x << " "<<shark_num<<endl;
}

void smellShark(int y, int x, int shark_num, int smell_second) {
	shark_smell[{y, x}] = { shark_num,smell_second };
}

void Solution(int n, int num_shark, int smell_second) {
	int times = 0;
	while (live_shark > 1) {
		// copy board
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				temp_board[i][j] = DIE;
			}
		}

		// move shark
		for (int i = 1; i <= num_shark; i++) {
			int loc_y = get<0>(shark[i]);
			int loc_x = get<1>(shark[i]);
			int dir_shark = get<2>(shark[i]);
			int shark_num = get<3>(shark[i]);
			if (shark_num == DIE) {
				continue;
			}
			moveShark(loc_y, loc_x, dir_shark, shark_num, n);
		}
		//cout << times << endl;
		// save board
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				board[i][j] = temp_board[i][j] == DIE ? 0 : temp_board[i][j];
			}
		}

		// smell down
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (shark_smell[{i, j}].second)
					shark_smell[{i, j}] = { shark_smell[{i,j}].first, shark_smell[{i,j}].second - 1 };
			}
		}
		// smell
		for (int i = 1; i <= num_shark; i++) {
			int loc_y = get<0>(shark[i]);
			int loc_x = get<1>(shark[i]);
			int dir_shark = get<2>(shark[i]);
			int shark_num = get<3>(shark[i]);
			if (shark_num == DIE) {
				continue;
			}
			smellShark(loc_y, loc_x, shark_num, smell_second);
		}

		times++;

		if (times > LIM) {
			times = -1;
			break;
		}
	}

	cout << times << endl;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int i, j; //for문 변수 -> longlong필요한지 확인
	int n, num_shark, smell_second; cin >> n >> num_shark >> smell_second;
	live_shark = num_shark;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> board[i][j];
			if (board[i][j]) {
				//shark.push({ i,j,0,board[i][j] });
				shark[board[i][j]] = { i,j,0,board[i][j] };
				shark_smell.insert({ {i,j},{board[i][j] ,smell_second } });
			}
			else {
				shark_smell.insert({ {i,j},{board[i][j] ,0 } });
			}
		}
	}
	for (int i = 1; i <= num_shark; i++) {
		int dir; cin >> dir;
		int loc_y = get<0>(shark[i]);
		int loc_x = get<1>(shark[i]);
		int shark_num = get<3>(shark[i]);
		shark[i] = { loc_y,loc_x,dir,shark_num };
	}
	for (int i = 1; i <= num_shark; i++) {
		for (int j = 0; j < DIR; j++) {
			int a, b, c, d; cin >> a >> b >> c >> d;
			shark_dir[i][j] = { a,b,c,d };
		}
	}

	Solution(n, num_shark, smell_second);
	return 0;
}