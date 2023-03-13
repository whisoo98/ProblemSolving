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

int arr[N][N];
int clean[N][N];
int y, x;
bool ok(int ty, int tx) {
	if (ty < 1 || ty>y || tx<1 || tx>x 
		|| arr[ty][tx] == 1 || clean[ty][tx] == 1) return false;
	return true;
}
int dx[] = { 0,-1,0,1 };
int dy[] = { -1 ,0,1,0};
int answer;
void Clean(int ty,int tx,int tdir) {
	int check = 1;
	int dir_check = 0;
	while (1) {
		//cout << "!";
		//cout << ty << " " << tx << " " << tdir << endl;
		if (check == 1) {
			answer++;
			clean[ty][tx] = 1;
			check = 0;
			dir_check = 0;
			continue;
		}
		if (ok(ty + dy[(tdir + 1) % 4], tx + dx[(tdir + 1) % 4])) {
			tdir++;
			tdir %= 4;
			ty += dy[tdir];
			tx += dx[tdir];
			check = 1;
			//dir_check++;
			continue;
		}
		else if(dir_check<4){
			tdir++;
			tdir %= 4;
			dir_check++;
		}
		else {
			
			if (arr[ty - dy[tdir]][tx - dx[tdir]] == 1) {
				break;
			}
			else{
				ty -= dy[tdir];
				tx -= dx[tdir];
				dir_check = 0;
			}
		}
	}
	
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, j; //for문 변수 -> longlong필요한지 확인
	cin >> y >> x;
	int sty, stx, stdir;
	
	cin >> sty >> stx >> stdir;
	if (stdir == 0) {
		stdir = 0;
	}
	else if (stdir == 1) {
		stdir = 3;
	}
	else if (stdir == 2) {
		stdir = 2;
	}
	else {
		stdir = 1;
	}
	sty++;
	stx++;
	for (i = 1; i <= y; i++) {
		for (j = 1; j <= x; j++) {
			cin >> arr[i][j];
		}
	}
	Clean(sty, stx, stdir);
	cout << answer;
	return 0;
}