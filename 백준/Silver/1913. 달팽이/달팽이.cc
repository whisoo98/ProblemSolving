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
#define N 1005
#define ll long long
#define endl "\n"
#define MID(a,b) (a+b)/2

using namespace std;

int arr[N][N];
int dy[] = { -1,0,1,0 };
int dx[] = { 0,1,0,-1 };

bool isOk(int ty, int tx, int y, int x) {
	if (ty<0 || ty>y - 1 || tx<0 || tx>x - 1)return false;
	return true;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, j; //for문 변수 -> longlong필요한지 확인
	int n; cin >> n;
	int find_number; cin >> find_number;
	int ansy, ansx;
	int nowy = n / 2 + dy[0];
	int nowx = n / 2 + dx[0];
	int dir = 0;
	int arr_number = 2;
	arr[n / 2][n / 2] = 1;
	int cnt = 0;
	int chk = 1;
	int chk2 = 0;
	for (int i = 0; i < n*n - 1; i++) {
		arr[nowy][nowx] = arr_number++;
		cnt++;
		if (cnt == chk) {
			cnt = 0;
			chk2++;
			dir++;
			dir %= 4;
		}
		if (chk2 == 2) {
			chk++;
			chk2 = 0;
		}
		nowy += dy[dir];
		nowx += dx[dir];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << arr[i][j] << " ";
			if (arr[i][j] == find_number) {
				ansy = i;
				ansx = j;
			}
		}
		cout << endl;
	}
	cout << ansy + 1 << " " << ansx + 1 << endl;
	return 0;
}