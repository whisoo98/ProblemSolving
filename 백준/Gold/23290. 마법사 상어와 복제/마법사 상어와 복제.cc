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
#define FISH_DIR 9
#define SHARK_DIR 5

using namespace std;

int fish_dy[] = { 0,0,-1,-1,-1,0,1,1,1 };
int fish_dx[] = { 0,-1,-1,0,1,1,1,0,-1 };
int shark_dy[] = { 0,-1,0,1,0 };
int shark_dx[] = { 0,0,-1,0,1 };
int fish_board[N][N][FISH_DIR];
int shark_fish_board[N][N];
int copy_magic_fish_board[N][N][FISH_DIR];
int fish_smell_board[N][N];
pair<int, int> shark;
string shark_moved_string[] = { "","up","left","down","right" };

bool isFishOk(int ty, int tx) {
	if (ty < 1 || ty>4 || tx < 1 || tx>4 || fish_smell_board[ty][tx]) return false;
	return true;
}

bool isSharkOk(int ty, int tx) {
	if (ty < 1 || ty>4 || tx < 1 || tx>4) return false;
	return true;
}

void debugFish() {
	for (int i = 1; i < N; i++) {
		for (int j = 1; j < N; j++) {
			int print_fish = 0;
			for (int k = 1; k < FISH_DIR; k++) {
				print_fish += fish_board[i][j][k];
			}
			cout << print_fish << " ";
		}
		cout << endl;
	}
	cout << endl;
}

void chargingCopyFishMagic() {
	for (int i = 1; i < N; i++) {
		for (int j = 1; j < N; j++) {
			for (int k = 1; k < FISH_DIR; k++) {
				copy_magic_fish_board[i][j][k] = fish_board[i][j][k];
			}
		}
	}
}

void moveFish() {
	int temp_fish_board[N][N][FISH_DIR];
	for (int i = 1; i < N; i++) {
		for (int j = 1; j < N; j++) {
			for (int k = 1; k < FISH_DIR; k++) {
				temp_fish_board[i][j][k] = 0;
			}
		}
	}
	int shark_y = shark.first;
	int shark_x = shark.second;
	for (int i = 1; i < N; i++) {
		for (int j = 1; j < N; j++) {
			int moved_y = i;
			int moved_x = j;
			for (int k = 1; k < FISH_DIR; k++) {
				int dir = k;
				for (int h = 1; h < FISH_DIR; h++) {
					int ty = i + fish_dy[dir];
					int tx = j + fish_dx[dir];
					if (isFishOk(ty, tx) && !(shark_y == ty && shark_x == tx)) {
						moved_y = ty;
						moved_x = tx;
						break;
					}
					else {
						dir--;
						if (dir == 0) {
							dir = 8;
						}
					}
				}
				temp_fish_board[moved_y][moved_x][dir] += fish_board[i][j][k];
			}
		}
	}
	for (int i = 1; i < N; i++) {
		for (int j = 1; j < N; j++) {
			for (int k = 1; k < FISH_DIR; k++) {
				fish_board[i][j][k] = temp_fish_board[i][j][k];
			}
		}
	}
}

void moveSharkStep(pair<int, int> shark_pos, int move_cnt,
	vector<int>& max_moved_seq, vector<int>& tot_moved_seq,
	int *max_cathed_fish,int tot_cathed_fish) {

	int catched_fish = 0;
	if (move_cnt == 4) {
		if (tot_cathed_fish > *max_cathed_fish) {
			*max_cathed_fish = tot_cathed_fish;
			max_moved_seq.clear();
			for (auto it : tot_moved_seq) {
				max_moved_seq.push_back(it);
			}
			return;
		}
	}
	else {
		int shark_y = shark_pos.first;
		int shark_x = shark_pos.second;
		for (int i = 1; i < SHARK_DIR; i++) {
			int now_catched_fish = 0;
			int ty = shark_y + shark_dy[i];
			int tx = shark_x + shark_dx[i];
			if (isSharkOk(ty, tx)) {
				now_catched_fish += shark_fish_board[ty][tx];
				shark_fish_board[ty][tx] = 0;
				tot_moved_seq.push_back(i);
				moveSharkStep({ ty,tx }, move_cnt + 1, max_moved_seq, tot_moved_seq, max_cathed_fish, tot_cathed_fish + now_catched_fish);
				tot_moved_seq.pop_back();
				catched_fish = max(now_catched_fish, catched_fish);
				shark_fish_board[ty][tx] = now_catched_fish;
			}
		}
	}
}

void moveShark() {
	int max_catched_fish = -1;
	int move1, move2, move3;
	for (int i = 1; i < N; i++) {
		for (int j = 1; j < N; j++) {
			shark_fish_board[i][j] = 0;
			for (int k = 1; k < FISH_DIR; k++) {
				shark_fish_board[i][j] += fish_board[i][j][k];
			}
		}
	}
	vector<int> max_moved_seq;
	vector<int> tot_moved_seq;
	moveSharkStep(shark, 1, max_moved_seq, tot_moved_seq, &max_catched_fish, 0);
	int shark_y = shark.first;
	int shark_x = shark.second;
	/*for (auto moved_dir : max_moved_seq) {
		
		cout << shark_moved_string[moved_dir] << " ";
	}
	cout << endl;*/

	for (auto moved_dir : max_moved_seq) {
		shark_y += shark_dy[moved_dir];
		shark_x += shark_dx[moved_dir];
		for (int dir = 1; dir < FISH_DIR; dir++) {
			if (fish_board[shark_y][shark_x][dir]) {
				fish_smell_board[shark_y][shark_x] = 3;
			}
			fish_board[shark_y][shark_x][dir] = 0;
		}
	}
	shark = { shark_y,shark_x };
}

void fishSmellDown() {
	for (int i = 1; i < N; i++) {
		for (int j = 1; j < N; j++) {
			if (fish_smell_board[i][j]) {
				fish_smell_board[i][j]--;
			}

		}
	}
}

void copyFishMagicComplete() {
	for (int i = 1; i < N; i++) {
		for (int j = 1; j < N; j++) {
			for (int k = 1; k < FISH_DIR; k++) {
				fish_board[i][j][k]+= copy_magic_fish_board[i][j][k];
			}
		}
	}
}

void Solution(int number_fish, int number_magic) {
	while (number_magic--) {
		// 1. charging Copy Fish Magic
		chargingCopyFishMagic();
		
		//debugFish();
		moveFish();
		//debugFish();

		moveShark();
		
		fishSmellDown();
		copyFishMagicComplete();

	}
	int ans = 0;
	for (int i = 1; i < N; i++) {
		for (int j = 1; j < N; j++) {
			for (int k = 1; k < FISH_DIR; k++) {
				ans+=fish_board[i][j][k];
			}
		}
	}
	cout << ans << endl;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, j; //for문 변수 -> longlong필요한지 확인
	int number_fish, number_magic; cin >> number_fish >> number_magic;
	for (int i = 0; i < number_fish; i++) {
		int y, x, dir; cin >> y >> x >> dir;
		fish_board[y][x][dir]++;
	}
	int y, x; cin >> y >> x;
	shark = { y,x };
	
	Solution(number_fish, number_magic);
	return 0;
}