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
#define N 5
#define ll long long
#define endl "\n"
#define MID(a,b) (a+b)/2

using namespace std;

//int fish_number[N][N];
//int fish_dir[N][N];
vector<pair<int, int>> fish_pos(20);
vector<vector<int>> fish_number(5);
vector<vector<int>> fish_dir(5);

pair<int, int> shark_pos;
int dy[] = {0, -1, -1, 0, 1, 1, 1, 0, -1 };
int dx[] = {0, 0, -1, -1, -1, 0, 1, 1, 1 };
int ans;

bool isOkFish(int ty, int tx) {
	if (ty < 0 || ty >= 4 || tx < 0 || tx >= 4 ||
		(ty == shark_pos.first && tx == shark_pos.second)) return false;
	return true;
}

bool isOkShark(int ty, int tx) {
	if (ty < 0 || ty >= 4 || tx < 0 || tx >= 4 ||
		fish_number[ty][tx] == 0) return false;
	return true;
}
void printFishInfo(int fish_dir) {
	string direction;
	switch (fish_dir) {
	case 1:
		direction = "상";
		break;
	case 2:
		direction = "좌상";
		break;
	case 3:
		direction = "좌";
		break;
	case 4:
		direction = "좌하";
		break;
	case 5:
		direction = "하";
		break;
	case 6:
		direction = "우하";
		break;
	case 7:
		direction = "우";
		break;
	case 8:
		direction = "우상";
		break;
	default:
		break;
	}
	cout << "fish dir : " << direction << endl;

}
void printSharkInfo(int lv, int next_shark_dir, int next_shark_eating) {
	string direction;
	switch (next_shark_dir) {
	case 1:
		direction = "상";
		break;
	case 2:
		direction = "좌상";
		break;
	case 3:
		direction = "좌";
		break;
	case 4:
		direction = "좌하";
		break;
	case 5:
		direction = "하";
		break;
	case 6:
		direction = "우하";
		break;
	case 7:
		direction = "우";
		break;
	case 8:
		direction = "우상";
		break;
	default:
		break;
	}
	cout << "shark lv : " << lv << endl;
	cout << "shark dir : " << direction << endl;
	cout << "shark eat : " << next_shark_eating << endl;
}
void moveFish() {
	for (int i = 1; i <= 16; i++) {
		int fish_y = fish_pos[i].first;
		int fish_x = fish_pos[i].second;
		if (fish_y == -1 && fish_x == -1) {
			continue;
		}
		/*cout << "-------------------------------------" << endl;
		cout << i << "번째 물고기 swap 전 ";
		printFishInfo(fish_dir[fish_y][fish_x]);

		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				if (i == shark_pos.first&& j == shark_pos.second) {
					cout << -4 << " ";
					continue;
				}
				cout << fish_number[i][j] << " ";
			}
			cout << endl;
		}
		cout << "-------------------------------------" << endl;*/
		

		int dir = fish_dir[fish_y][fish_x];
		int ty, tx;

		int chk = 0;
		while (chk < 8) {
			ty = fish_y + dy[dir];
			tx = fish_x + dx[dir];
			if (isOkFish(ty, tx)) {

				int change_fish = fish_number[ty][tx];
				int change_fish_y = ty;
				int change_fish_x = tx;
				int change_fish_dir = fish_dir[change_fish_y][change_fish_x];

				swap(fish_y, change_fish_y);
				swap(fish_x, change_fish_x);

				fish_number[fish_y][fish_x] = i;
				fish_dir[fish_y][fish_x] = dir;
				fish_pos[i] = { fish_y,fish_x };

				fish_number[change_fish_y][change_fish_x] = change_fish;
				fish_dir[change_fish_y][change_fish_x] = change_fish_dir;
				fish_pos[change_fish] = { change_fish_y,change_fish_x };
				break;
			}
			else {
				chk++;
				dir += 1;
				if (dir == 9) dir = 1;
			}
		}
		//cout << "-------------------------------------" << endl;
		//cout << i << "번째 물고기 swap 후 ";
		//printFishInfo(fish_dir[fish_y][fish_x]);

		//for (int i = 0; i < 4; i++) {
		//	for (int j = 0; j < 4; j++) {
		//		if (i == shark_pos.first&& j == shark_pos.second) {
		//			cout << -4 << " ";
		//			continue;
		//		}
		//		cout << fish_number[i][j] << " ";
		//	}
		//	cout << endl;
		//}
		//cout << "-------------------------------------" << endl;
	}
}

void eatFish(int fish_y, int fish_x, int* shark_dir, int* shark_eating) {
	*shark_dir = fish_dir[fish_y][fish_x];
	*shark_eating = fish_number[fish_y][fish_x];
	shark_pos = { fish_y,fish_x };

	fish_dir[fish_y][fish_x] = 0;
	fish_number[fish_y][fish_x] = 0;
	fish_pos[*shark_eating] = { -1,-1 };
}

void moveShark(int shark_y, int shark_x, int shark_dir, int eating,int lv) {
	//cout << "lv : "<< lv<< " " <<shark_y << " " << shark_x << " " <<shark_dir << " "<< eating << endl;
	//cout << shark_y << " " << shark_x << endl;
	//printSharkInfo(lv, shark_dir, eating);

	ans = max(ans, eating);
	moveFish();
	vector<pair<int, int>> save_fish_pos(fish_pos);

	vector<vector<int>> save_fish_number(fish_number);
	vector<vector<int>> save_fish_dir(fish_dir);
	int sz = fish_pos.size();
	for (int i = 0; i < sz; i++) {
		save_fish_pos[i] = fish_pos[i];
	}
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			save_fish_number[i][j] = fish_number[i][j];
			save_fish_dir[i][j] = fish_dir[i][j];
		}
	}
	int ty, tx;
	for (int i = 1; i < 5; i++) {
		ty = shark_y + dy[shark_dir] * i;
		tx = shark_x + dx[shark_dir] * i;
		if (isOkShark(ty, tx)) {
			int next_shark_dir;
			int next_shark_eating;
			eatFish(ty, tx, &next_shark_dir, &next_shark_eating);
			/*cout << "-------------------------------------" << endl;
			printSharkInfo(lv, next_shark_dir, next_shark_eating);

			for (int i = 0; i < 4; i++) {
				for (int j = 0; j < 4; j++) {
					if (i == shark_pos.first&& j == shark_pos.second) {
						cout << -4 << " ";
						continue;
					}
					cout << fish_number[i][j] << " ";
				}
				cout << endl;
			}
			cout << "-------------------------------------" << endl;*/
			moveShark(ty, tx, next_shark_dir, eating + next_shark_eating,lv+1);
			/*fish_pos = save_fish_pos;
			fish_number = save_fish_number;
			fish_dir = save_fish_dir;*/
			for (int i = 0; i < sz; i++) {
				fish_pos[i] = save_fish_pos[i];
			}
			for (int i = 0; i < 5; i++) {
				for (int j = 0; j < 5; j++) {
					fish_number[i][j] = save_fish_number[i][j];
					fish_dir[i][j] = save_fish_dir[i][j];
				}
			}
			shark_pos = { shark_y,shark_x };
		}
	}
}


void Solution() {
	int shark_dir;
	int shark_eating;
	eatFish(0, 0, &shark_dir, &shark_eating);
	/*fish_dir[0][0] = 0;
	fish_number[0][0] = 0;
	fish_pos[shark_eating] = { -1,-1 };*/
	//shark_pos = { 0,0 };
	moveShark(0, 0, shark_dir, shark_eating,1);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, j; //for문 변수 -> longlong필요한지 확인
	int n = 4;
	for (int i = 0; i < n; i++) {
		vector<int> fish_row(5,0);
		vector<int> dir_row(5,0);
		for (int j = 0; j < n; j++) {
			int fish, dir; cin >> fish >> dir;
			fish_row[j]=fish;
			dir_row[j]=dir;
			fish_pos[fish] = { i,j };
		}
		fish_number[i]=fish_row;
		fish_dir[i]=dir_row;
	}
	vector<int> fish_row(5, 0);
	vector<int> dir_row(5, 0);
	fish_number[4] = fish_row;
	fish_dir[4] = dir_row;
	/*for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << fish_number[i][j] << " " ;
		}
		cout << endl;
	}
	for (int i = 1; i <= 16; i++) {
		cout << fish_pos[i].first<< " "<<fish_pos[i].second << endl;
	}*/
	cout.precision(3);
	Solution();
	cout << ans << endl;
	return 0;
}