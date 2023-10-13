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
#define N 55
#define ll long long
#define endl "\n"
#define MID(a,b) (a+b)/2
#define U 1
#define D 2
#define L 3
#define R 4
using namespace std;


int board[N][N];
vector<pair<int, int>> magic_info;
int boom_bead_count_arr[5];
int n, number_magic;
pair<int, int> shark;
int dy[] = { 0,-1,1,0,0 };
int dx[] = { 0,0,0,-1,1 };
int ddir[] = { 0,L,R,D,U };
map<pair<int, int>, int> location_to_number;
map<int, pair<int, int>> number_to_location;

bool isOk(int ty, int tx, int diff) {
	if (ty < 1 || ty > n+ diff || tx < 1 || tx > n+ diff) return false;
	return true;
}

void preProcess() {
	int ty = shark.first;
	int tx = shark.second;
	int dir = L;
	int reach_end = 0;
	int location_number = 1;
	int counting = 1;
	while (!reach_end) {
		for (int turn = 0; turn < 2; turn++, dir = ddir[dir]) {
			for (int count = 0; count < counting; count++) {
				ty = ty + dy[dir];
				tx = tx + dx[dir];
				location_to_number.insert({ {ty,tx}, location_number });
				number_to_location.insert({ location_number,{ty,tx} });
				location_number++;
				if (!isOk(ty, tx, 1)) {
					reach_end = 1;
					break;
				}
			}
		}
		counting++;
	}
}

void blastBlizzard(int magic_number) {
	int magic_dir = magic_info[magic_number].first;
	int magic_len = magic_info[magic_number].second;
	for (int i = 1; i <= magic_len; i++) {
		int ty = shark.first + i * dy[magic_dir];
		int tx = shark.second + i * dx[magic_dir];
		board[ty][tx] = 0;
	}
}



void compactBeads() {
	int empty_bead = 0;
	for (int i = 1; i <= n * n - 1; i++) {
		int loc_y = number_to_location[i].first;
		int loc_x = number_to_location[i].second;
		if (board[loc_y][loc_x] == 0) {

			int fill_y = number_to_location[i - empty_bead].first;
			int fill_x = number_to_location[i - empty_bead].second;
			board[fill_y][fill_x] = board[loc_y][loc_x];

			empty_bead++;
			continue;
		}
		else {
			if (!empty_bead) {
				continue;
			}
			else {
				int fill_y = number_to_location[i - empty_bead].first;
				int fill_x = number_to_location[i - empty_bead].second;
				board[fill_y][fill_x] = board[loc_y][loc_x];
				board[loc_y][loc_x] = 0;
			}
		}
	}
}

int boomBeads() {
	int boomed_cnt = 0;
	int loc_y = number_to_location[1].first;
	int loc_x = number_to_location[1].second;
	int before_bead_number = board[loc_y][loc_x];
	int cnt = 1;
	for (int i = 2; i <= n * n; i++) {
		loc_y = number_to_location[i].first;
		loc_x = number_to_location[i].second;
		int bead_number = board[loc_y][loc_x];
		if (before_bead_number == bead_number) {
			cnt++;
		}
		else {
			if (cnt >= 4) {
				int boom_end = i - 1;
				int boom_start = i - cnt;
				for (int boom = boom_start; boom <= boom_end; boom++) {
					int boom_y = number_to_location[boom].first;
					int boom_x = number_to_location[boom].second;
					board[boom_y][boom_x] = 0;
				}
				boomed_cnt += boom_end - boom_start + 1;
				boom_bead_count_arr[before_bead_number] += boom_end - boom_start + 1;
			}
			before_bead_number = bead_number;
			cnt = 1;
		}
	}
	return boomed_cnt;
}



void changeBeads() {
	vector<pair<int, int>> bead_group;
	int loc_y = number_to_location[1].first;
	int loc_x = number_to_location[1].second;
	int before_bead_number = board[loc_y][loc_x];
	if (before_bead_number == 0) {
		return;
	}
	int cnt = 1;
	for (int i = 2; i <= n * n - 1; i++) {
		loc_y = number_to_location[i].first;
		loc_x = number_to_location[i].second;
		int bead_number = board[loc_y][loc_x];
		if (before_bead_number == bead_number) {
			cnt++;
		}
		else {
			bead_group.push_back({ cnt, before_bead_number });
			before_bead_number = bead_number;
			cnt = 1;
			if (before_bead_number == 0)
				break;
		}
	}
	int group_idx = 0;
	for (int i = 1; i <= n * n - 1 && group_idx<bead_group.size(); i += 2, group_idx++) {
		int group_bead_cnt = bead_group[group_idx].first;
		int group_bead_number = bead_group[group_idx].second;

		int loc_y = number_to_location[i].first;
		int loc_x = number_to_location[i].second;
		board[loc_y][loc_x] = group_bead_cnt;

		loc_y = number_to_location[i + 1].first;
		loc_x = number_to_location[i + 1].second;
		board[loc_y][loc_x] = group_bead_number;
	}
}


void debugBlizzard() {
	cout.fill(2);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			int board_number = location_to_number[{i, j}];
			//cout << board_number << " ";
			cout << board[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

void Solution() {
	preProcess();
	for (int i = 0; i < number_magic; i++) {
		blastBlizzard(i);
		//cout << "---------INIT---------" << endl;
		//debugBlizzard();

		int boomed = 1;
		while (boomed) {
			compactBeads();
			//debugBlizzard();
			boomed = boomBeads();
			//cout << i;
		}
		//cout << endl;
	 	//debugBlizzard();
		changeBeads();
		//cout << "---------END---------" << endl;

	}
	ll ans = 0;
	for (int i = 1; i <= 3; i++) {
		ans += (ll)i * (ll)boom_bead_count_arr[i];
	}
	cout << ans << endl;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, j; //for문 변수 -> longlong필요한지 확인
	cin >> n >> number_magic;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> board[i][j];
		}
	}
	for (int i = 0; i < number_magic; i++) {
		int magic_dir, magic_len; cin >> magic_dir >> magic_len;
		magic_info.push_back({ magic_dir, magic_len });
	}
	shark = { n / 2 + 1,n / 2 + 1 };
	Solution();
	return 0;
}