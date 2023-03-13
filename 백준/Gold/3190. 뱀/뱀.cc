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

using namespace std;

int arr[N][N];
char moving[10005];
int dy[] = { 0,1,0,-1 };
int dx[] = { 1,0,-1,0 };
deque<pair<int, int>> tail;
bool ok(int ty, int tx, int n) {
	if (ty<1 || ty>n || tx<1 || tx>n ) return false;
	return true;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, j; //for문 변수 -> longlong필요한지 확인
	int n, k; cin >> n >> k;
	for (i = 1; i <= k; i++) {
		int y, x; cin >> y >> x;
		arr[y][x] = 1;
	}
	int l; cin >> l;
	for (i = 1; i <= l; i++) {
		int a; char cmd; cin >> a >> cmd;
		moving[a] = cmd;
	}
	int sty = 1, stx = 1;
	int dir = 0;
	int edy = 1, edx = 1;
	tail.push_back({ 1,1 });
	int time = 0;
	while (1) {
		//cout << time<<" "<< sty << " " << stx << endl;
		int ty = sty + dy[dir];
		int tx = stx + dx[dir];
		//arr[edy][edx] = 0;
		if (ok(ty, tx, n)==false || arr[ty][tx] == -1) break;
		//sty = ty; stx = tx;
		//arr[sty][stx] = -1;
		tail.push_back({ ty,tx });
		time++;
		if (arr[ty][tx] == 1) {
			arr[edy][edx] = -1;
			sty = ty; stx = tx;
			arr[sty][stx] = -1;

			if (moving[time] != 0) {
				if (moving[time] == 'D') {
					dir++;
					dir %= 4;
				}
				else {
					dir += 3;
					dir %= 4;
				}
			}
		}
		else {
			arr[edy][edx] = 0;
			sty = ty; stx = tx;
			arr[sty][stx] = -1;
			tail.pop_front();
			edy = tail.front().first;
			edx = tail.front().second;
			if (moving[time] != 0) {
				if (moving[time] == 'D') {
					dir++;
					dir %= 4;
				}
				else {
					dir += 3;
					dir %= 4;
				}
			}
			
		}
	}
	cout << time+1;
	return 0;
}