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

using namespace std;

int board[N][N];
int cloud_board[N][N];
int dy[] = { 0,-1,-1,-1,0,1,1,1 };
int dx[] = { -1,-1,0,1,1,1,0,-1 };
int n, number_magic;
vector<pair<int, int>> magic_info;
vector<pair<int, int>> cloud_info;

bool isOk(int ty, int tx) {
	if (ty<1 || ty>n || tx<1 || tx>n) return false;
	return true;
}

void initCloud() {
	cloud_info = { {n,1},{n,2},{n - 1,1},{n - 1,2} };
}

void moveCloud(int magic_number) {
	int magic_dir = magic_info[magic_number].first;
	int magic_len = magic_info[magic_number].second;
	int sz = cloud_info.size();
	for (int i = 0; i < sz;i++) {
		auto cloud_iter = cloud_info[i];
		int cloud_y = cloud_iter.first;
		int cloud_x = cloud_iter.second;
		
		int moved_y = cloud_y;
		int moved_x = cloud_x;

		for (int j = 1; j <= magic_len; j++) {
			moved_y = moved_y + dy[magic_dir];
			if (moved_y == 0) {
				moved_y = n;
			}
			else if (moved_y == n + 1) {
				moved_y = 1;
			}

			moved_x = moved_x + dx[magic_dir];
			if (moved_x == 0) {
				moved_x = n;
			}
			else if (moved_x == n + 1) {
				moved_x = 1;
			}
		}

		cloud_info[i] = { moved_y,moved_x };
	}
}

void doRain() {
	for (auto cloud_iter : cloud_info) {
		int cloud_y = cloud_iter.first;
		int cloud_x = cloud_iter.second;
		board[cloud_y][cloud_x]++;
	}
}

void dummydeleteCloud() {

}

void waterCopyBugMagic() {
	// diagonal : 1,3,5,7
	for (auto cloud_iter : cloud_info) {
		int cloud_y = cloud_iter.first;
		int cloud_x = cloud_iter.second;
		int add_water = 0;
		for (int i = 1; i <= 7; i += 2) {
			int ty = cloud_y + dy[i];
			int tx = cloud_x + dx[i];
			if (isOk(ty, tx) && board[ty][tx]) {
				add_water++;
			}
		}
		//cout << cloud_y << " " << cloud_x << " " << add_water << endl;
		board[cloud_y][cloud_x] += add_water;
		cloud_board[cloud_y][cloud_x] = 1;
	}
	cloud_info.clear();
}

void makeCloud() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (board[i][j] >= 2 && !cloud_board[i][j]) {
				cloud_info.push_back({ i,j });
				board[i][j] -= 2;
			}
			cloud_board[i][j] = 0;
		}
	}
}

int sumWater() {
	int ret = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			ret += board[i][j];
		}
	}
	return ret;
}

void debugCloud() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cout << board[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}
void Solution() {
	initCloud();
	for (int i = 0; i < number_magic; i++) {
		moveCloud(i);
		doRain();
		dummydeleteCloud();
		waterCopyBugMagic();
		//debugCloud();
		makeCloud();
	}
	int ans = 0;
	ans += sumWater();
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
		magic_info.push_back({ magic_dir - 1, magic_len });
	}
	Solution();
	return 0;
}