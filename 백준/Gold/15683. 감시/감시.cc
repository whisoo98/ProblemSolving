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
#define N 10
#define ll long long
#define endl "\n"
#define MID(a,b) (a+b)/2

using namespace std;

class CCTV {
public:
	int number;
	int y;
	int x;
	//int dir;
};

CCTV cctv[N];
int num_cctv;
int office[N][N];

int _right[6][5] = {
	{},
	{ 0,1,0,0,0 },
	{ 0,1,0,1,0 },
	{ 0,1,0,0,1 },
	{ 0,1,0,1,1 },
	{ 0,1,1,1,1 },

};
int _left[6][5] = {
	{},
	{ 0,0,0,1,0 },
	{ 0,1,0,1,0 },
	{ 0,0,1,1,0 },
	{ 0,1,1,1,0 },
	{ 0,1,1,1,1 },

};
int _up[6][5] = {
	{},
	{ 0,0,1,0,0 },
	{ 0,0,1,0,1 },
	{ 0,1,1,0,0 },
	{ 0,1,1,0,1 },
	{ 0,1,1,1,1 },

};
int _down[6][5] = {
	{},
	{ 0,0,0,0,1 },
	{ 0,0,1,0,1 },
	{ 0,0,0,1,1 },
	{ 0,0,1,1,1 },
	{ 0,1,1,1,1 },

};

bool isOk(int ty, int tx, int y, int x) {
	if (ty<1 || ty>y || tx<1 || tx>x)return false;
	return true;
}
void copyStates(CCTV src_cctv[N], CCTV dst_cctv[N], int src_office[N][N], int dst_office[N][N], int y, int x) {
	for (int i = 0; i < num_cctv;i++) {
		dst_cctv[i].number = src_cctv[i].number;
		dst_cctv[i].y = src_cctv[i].y;
		dst_cctv[i].x = src_cctv[i].x;
		//dst_cctv[i].dir = src_cctv[i].dir;
	}
	for (int i = 1; i <= y; i++) {
		for (int j = 1; j <= x; j++) {
			dst_office[i][j] = src_office[i][j];
		}
	}
}

int ans;
int del;
int deleteOffice(int lv, int dir, int y, int x) {
	int cy = cctv[lv].y;
	int cx = cctv[lv].x;
	int tright = _right[cctv[lv].number][dir];
	int tleft = _left[cctv[lv].number][dir];
	int tup = _up[cctv[lv].number][dir];
	int tdown = _down[cctv[lv].number][dir];
	int deleted = 0;
	if (tup) {
		for (int i = 1; i <= y; i++) {
			int ty = cy - tup * i;
			int tx = cx;
			if (isOk(ty, tx, y, x)) {
				if (office[ty][tx] == 6)
					break;
				else if(office[ty][tx] == 0) {
					office[ty][tx] = -1;
					deleted++;
				}
				else {
					continue;
				}
			}
		}
	}
	if (tdown) {
		for (int i = 1; i <= y; i++) {
			int ty = cy + tdown * i;
			int tx = cx;
			if (isOk(ty, tx, y, x)) {
				if (office[ty][tx] == 6)
					break;
				else if (office[ty][tx] == 0) {
					office[ty][tx] = -1;
					deleted++;
				}
				else {
					continue;
				}
			}
		}
	}
	if (tleft) {
		for (int i = 1; i <= x; i++) {
			int ty = cy;
			int tx = cx - tleft * i;
			if (isOk(ty, tx, y, x)) {
				if (office[ty][tx] == 6)
					break;
				else if (office[ty][tx] == 0) {
					office[ty][tx] = -1;
					deleted++;
				}
				else {
					continue;
				}
			}
		}
	}
	if (tright) {
		for (int i = 1; i <= x; i++) {
			//cout << "tright : "<< tright << endl;
			int ty = cy;
			int tx = cx + tright * i;
			if (isOk(ty, tx, y, x)) {
				if (office[ty][tx] == 6)
					break;
				else if (office[ty][tx] == 0) {
					//cout << "DEL" << endl;
					office[ty][tx] = -1;
					deleted++;
				}
				else {
					continue;
				}
			}
		}
	}
	return deleted;
}
void dfs(int y, int x, int lv, int deleted) {
	del = max(del, deleted);
	if (lv >= num_cctv) return;
	CCTV t_cctv[N];
	int t_office[N][N];
	/*cout << "--------------------------------------" << endl;
	cout << "before office : lv : " << lv << endl;
	for (int i = 1; i <= y; i++) {
		for (int j = 1; j <= x; j++) {
			cout << office[i][j] << " ";
		}
		cout << endl;
	}
	cout << "--------------------------------------" << endl;*/

	copyStates(cctv, t_cctv, office, t_office, y, x);
	for (int dir = 1; dir <= 4; dir++) {
		int cnt =deleteOffice(lv, dir,y,x);
		dfs(y, x, lv + 1, deleted + cnt);
		copyStates(t_cctv, cctv, t_office, office, y, x);
		/*cout << "--------------------------------------" << endl;
		cout << "after office : lv : " << lv << endl;
		for (int i = 1; i <= y; i++) {
			for (int j = 1; j <= x; j++) {
				cout << office[i][j] << " ";
			}
			cout << endl;
		}
		cout << "--------------------------------------" << endl;*/
		/*if (cctv[lv].number == 2) {
			if (dir >= 2) break;
		}
		else if (cctv[lv].number == 5) {
			break;
		}*/
	}
}


void Solution(int y, int x){
	dfs(y, x, 0, 0);
	cout << ans - del << endl;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, j; //for문 변수 -> longlong필요한지 확인
	int y, x; cin >> y >> x;
	

	for (int i = 1; i <= y; i++) {
		for (int j = 1; j <= x; j++) {
			int a;
			cin >> a;
			if (a != 0 && a!=6) {
				cctv[num_cctv].number = a;
				cctv[num_cctv].y = i;
				cctv[num_cctv].x = j;
				//cctv[num_cctv].dir = 1;
				num_cctv++;
			}
			office[i][j] = a;
			if (office[i][j] == 0)
				ans++;
		}
	}
	Solution(y, x);
	return 0;
}