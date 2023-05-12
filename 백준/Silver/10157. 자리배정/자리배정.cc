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
int y, x;
int k;
int seats[N][N];

bool isOk(int ty, int tx) {
	if (ty<1 || ty>y || tx<1 || tx>x || seats[ty][tx]) return false;
	return true;
}
void matching() {
	int cnt = 1;
	int loop = 1;
	int ansy, ansx;
	int i = 1, j = 1;
	while (loop) {
		for (;isOk(i,j); i++) {
			if (cnt == k) {
				loop = 0;
				ansy = i;
				ansx = j;
				break;
			}
			seats[i][j] = cnt++;
		}
		if (!loop) break;
		i--;
		j++;
		for (; isOk(i, j); j++) {
			if (cnt == k) {
				loop = 0;
				ansy = i;
				ansx = j;
				break;
			}
			seats[i][j] = cnt++;
		}
		if (!loop) break;

		j--;
		i--;

		for (; isOk(i, j); i--) {
			if (cnt == k) {
				loop = 0;
				ansy = i;
				ansx = j;
				break;
			}
			seats[i][j] = cnt++;
		}
		if (!loop) break;

		i++;
		j--;
		for (; isOk(i, j); j--) {
			if (cnt == k) {
				loop = 0;
				ansy = i;
				ansx = j;
				break;
			}
			seats[i][j] = cnt++;
		}
		if (!loop) break;

		j++;
		i++;
	}
	cout << ansx << " " << ansy << endl;
}

void Solution() {
	if (k > y*x) {
		cout << 0 << endl;
	}
	else {
		matching();
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, j; //for문 변수 -> longlong필요한지 확인
	cin >> x >> y;
	cin >> k;
	Solution();
	return 0;
}