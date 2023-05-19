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


char candies[N][N];
int dy[] = { 0,0,1,-1 };
int dx[] = { 1,-1,0,0 };

bool isOk(int ty, int tx, int y, int x) {
	if (ty < 1 || ty>y || tx<1 || tx>x)return false;
	return true;
}
int ans;
int checkCandy(int n) {
	int contiguous = 0;
	for (int i = 1; i <= n; i++) {
		int flag;
		int temp = 0;
		for (int j = 1; j <= n; j++) {
			if (j == 1) {
				flag = candies[i][j];
				temp = 1;
				continue;
			}
			if (candies[i][j] == flag) {
				temp++;
			}
			else {
				contiguous = max(contiguous, temp);
				flag = candies[i][j];
				temp = 1;
			}
		}
		contiguous = max(contiguous, temp);
	}

	for (int j = 1; j <= n; j++) {
		int flag;
		int temp = 0;
		for (int i = 1; i <= n; i++) {
			if (i == 1) {
				flag = candies[i][j];
				temp = 1;
				continue;
			}
			if (candies[i][j] == flag) {
				temp++;
			}
			else {
				contiguous = max(contiguous, temp);
				flag = candies[i][j];
				temp = 1;

			}
		}
		contiguous = max(contiguous, temp);
	}
	return contiguous;
}
void mvCandy(int srcy, int srcx, int desty, int destx) {
	char temp = candies[srcy][srcx];
	candies[srcy][srcx] = candies[desty][destx];
	candies[desty][destx]=temp;
}
void Solution(int n) {
	ans = checkCandy(n);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			for (int d = 0; d < 4; d++) {
				int ty = i + dy[d];
				int tx = j + dx[d];
				if (isOk(ty, tx,n,n)) {
					mvCandy(i, j, ty, tx);
					ans = max(checkCandy(n),ans);
					mvCandy(ty, tx, i, j);
				}
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
	int n; cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> candies[i][j];
		}
	}
	Solution(n);
	return 0;
}