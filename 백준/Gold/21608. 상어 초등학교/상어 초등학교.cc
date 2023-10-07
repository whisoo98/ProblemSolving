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
#define N 25
#define ll long long
#define endl "\n"
#define MID(a,b) (a+b)/2

using namespace std;

int seats[N][N];
int empty_seat[N][N];
map<int, pair<int, int>> stud_point;
vector<vector<int>> preference;
vector<int> student;
int dy[] = { 0,0,-1,1 };
int dx[] = { -1,1,0,0 };
int stud_index[N*N];
ll ans;

bool isOk(int ty, int tx, int y, int x) {
	if (ty<1 || ty > y || tx < 1 || tx >x) return false;
	return true;
}

void poseStudent(int idx, int stud, int n) {
	vector<pair<int, int>> pref_point;
	int temp_seats[N][N];
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			temp_seats[i][j] = 0;
		}
	}
	// check empty space upon pref stud
	for (auto pref_stud : preference[idx]) {
		if (stud_point.count(pref_stud) == 0)
			continue;
		int pref_stud_y = stud_point[pref_stud].first;
		int pref_stud_x = stud_point[pref_stud].second;
		for (int k = 0; k < 4; k++) {
			int ty = pref_stud_y + dy[k];
			int tx = pref_stud_x + dx[k];
			if (isOk(ty, tx, n, n) && !seats[ty][tx]) {
				temp_seats[ty][tx]++;
				pref_point.push_back({ ty,tx });
			}
		}
	}
	sort(pref_point.begin(), pref_point.end());
	pref_point.erase(unique(pref_point.begin(), pref_point.end()), pref_point.end());
	int seat_y, seat_x;
	int num_pref = -1;
	int num_empty = -1;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++){
			if (temp_seats[i][j] >= num_pref && !seats[i][j]) {
				if (temp_seats[i][j] > num_pref) {
					num_pref = temp_seats[i][j];
					num_empty = empty_seat[i][j];
					seat_y = i;
					seat_x = j;
				}
				else {
					if (empty_seat[i][j] > num_empty) {
						num_empty = empty_seat[i][j];
						seat_y = i;
						seat_x = j;
					}
				}
			}
		}
	}

	/*for (auto it : pref_point) {
		int candid_seat_y = it.first;
		int candid_seat_x = it.second;
		if (temp_seats[candid_seat_y][candid_seat_x] >= num_pref) {
			if (temp_seats[candid_seat_y][candid_seat_x] > num_pref) {
				num_pref = temp_seats[candid_seat_y][candid_seat_x];
				num_empty = empty_seat[candid_seat_y][candid_seat_x];
				seat_y = candid_seat_y;
				seat_x = candid_seat_x;
			}
			else if (empty_seat[candid_seat_y][candid_seat_x] > num_empty) {
				num_empty = empty_seat[candid_seat_y][candid_seat_x];
				seat_y = candid_seat_y;
				seat_x = candid_seat_x;
			}
		}
	}
	if (num_pref == -1) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (empty_seat[i][j] > num_empty) {
					num_empty = empty_seat[i][j];
					seat_y = i;
					seat_x = j;
				}
			}
		}
	}*/
	seats[seat_y][seat_x] = stud;
	empty_seat[seat_y][seat_x] = 0;
	stud_point[stud] = { seat_y,seat_x };
}

void postProcess(int stud, int n) {
	int seat_y = stud_point[stud].first;
	int seat_x = stud_point[stud].second;
	for (int k = 0; k < 4; k++) {
		int ty = seat_y + dy[k];
		int tx = seat_x + dx[k];
		if (isOk(ty, tx, n, n) && !seats[ty][tx]) {
			empty_seat[ty][tx]--;
			empty_seat[ty][tx] = max(empty_seat[ty][tx], 0);
		}
	}
}

void calcSatisfy(int n) {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			int num_pref = 0;
			int stud = seats[i][j];
			for (int k = 0; k < 4; k++) {
				int ty = i + dy[k];
				int tx = j + dx[k];
				if (isOk(ty, tx, n, n)) {
					for (auto pref : preference[stud_index[stud]]) {
						if (pref == seats[ty][tx])
							num_pref++;
					}
				}
			}
			ll add = num_pref ? (ll)powl(10, num_pref - 1) : 0;
			ans += add;
		}
	}
}

void Solution(int n) {
	for (int i = 0; i < n*n; i++) {
		// choose studend;
		int stud = student[i];
		// pose to seats
		poseStudent(i, stud, n);
		// postprocess 
		// empty_seat handle
		postProcess(stud, n);
	}
	calcSatisfy(n);
	cout << ans << endl;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, j; //for문 변수 -> longlong필요한지 확인
	int n; cin >> n;
	for (int i = 0; i < n*n; i++) {
		int stud; cin >> stud;
		stud_index[stud] = i;
		student.push_back(stud);
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		vector<int> tv = { a,b,c,d };
		preference.push_back(tv);
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			empty_seat[i][j] = 4;
			if (i == 1 || i == n) empty_seat[i][j]--;
			if (j == 1 || j == n)  empty_seat[i][j]--;
		}
	}

	Solution(n);
	return 0;
}