#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


struct fish {
	int num;
	int y;
	int x;
	int dir;

	void set_pos(int num, int y, int x, int dir) {
		this->num = num;
		this->y = y;
		this->x = x;
		this->dir = dir;
	}

	void rotate() {
		dir = (dir + 1) % 8;
	}
};

int dy[8] = { -1, -1, 0, 1, 1, 1, 0, -1 };
int dx[8] = { 0, -1, -1, -1, 0, 1, 1, 1 };

int board[4][4];

fish fishs[17];
fish shark;


bool is_in_range(int y, int x) {
	if (y >= 0 && y < 4 && x >= 0 && x < 4 && !(y == shark.y && x == shark.x)) {
		return true;
	}
	else {
		return false;
	}
}

void swap_pos(fish& f1, fish& f2) {
	fish temp_fish;
	temp_fish.y = f1.y;
	temp_fish.x = f1.x;
	int f1_num = board[f1.y][f1.x];

	board[f1.y][f1.x] = board[f2.y][f2.x];
	f1.y = f2.y;
	f1.x = f2.x;

	board[f2.y][f2.x] = f1_num;
	f2.y = temp_fish.y;
	f2.x = temp_fish.x;
}

void move_fishs() {
	int ny, nx;

	for (int i = 1; i <= 16; i++) {
		//아직 죽지 않았을 때
		if (fishs[i].num != -1) {
			for (int j = 0; j < 8; j++) {
				ny = fishs[i].y + dy[fishs[i].dir];
				nx = fishs[i].x + dx[fishs[i].dir];

				if (is_in_range(ny, nx)) {
					swap_pos(fishs[board[ny][nx]], fishs[board[fishs[i].y][fishs[i].x]]);
					break;
				}
				else {
					fishs[i].rotate();
				}

			}
		}
	}
}


int sol(int step) {

	move_fishs();

	int board_copy[4][4];
	fish fishs_copy[17];
	fish shark_copy;

	int dead_score = 0;
	int max_score = 0;

	for (int j = 0; j < 4; j++) {
		for (int k = 0; k < 4; k++) {
			board_copy[j][k] = board[j][k];
		}
	}
	for (int j = 1; j <= 16; j++) {
		fishs_copy[j].num = fishs[j].num;
		fishs_copy[j].y = fishs[j].y;
		fishs_copy[j].x = fishs[j].x;
		fishs_copy[j].dir = fishs[j].dir;
	}
	shark_copy.num = shark.num;
	shark_copy.y = shark.y;
	shark_copy.x = shark.x;
	shark_copy.dir = shark.dir;

	for (int i = 1; i <= 3; i++) {
		int ny = shark.y + i * dy[shark.dir];
		int nx = shark.x + i * dx[shark.dir];
		if (ny >= 0 && ny < 4 && nx >= 0 && nx < 4) {
			if (fishs[board[ny][nx]].num != -1) {
				dead_score = fishs[board[ny][nx]].num;
				shark.y = fishs[board[ny][nx]].y;
				shark.x = fishs[board[ny][nx]].x;
				shark.dir = fishs[board[ny][nx]].dir;

				fishs[board[ny][nx]].num = -1;
				//board[ny][nx] = -1;

				int temp = sol(step + 1);
				max_score = max(max_score, temp + dead_score);



				for (int j = 0; j < 4; j++) {
					for (int k = 0; k < 4; k++) {
						board[j][k] = board_copy[j][k];
					}
				}
				for (int j = 1; j <= 16; j++) {
					fishs[j].num = fishs_copy[j].num;
					fishs[j].y = fishs_copy[j].y;
					fishs[j].x = fishs_copy[j].x;
					fishs[j].dir = fishs_copy[j].dir;
				}
				shark.num = shark_copy.num;
				shark.y = shark_copy.y;
				shark.x = shark_copy.x;
				shark.dir = shark_copy.dir;
			}
		}
	}

	return max_score;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int num, dir;

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			cin >> num >> dir;
			fishs[num].set_pos(num, i, j, dir - 1);
			board[i][j] = num;

			if (i == 0 && j == 0) {
				shark.set_pos(num, 0, 0, dir - 1);
				// board[i][j] = -1;
				fishs[num].num = -1;
			}
		}
	}

	//cout << sol(0) << "bb\n";
	//cout << shark.num << "aa\n";
	cout << sol(0) + shark.num << endl;

	return 0;
}