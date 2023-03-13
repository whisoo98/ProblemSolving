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
#define N 3000
#define ll long long
#define endl "\n"
#define MID(a,b) (a+b)/2

using namespace std;

int arr[N][N];
int cnt[5];
void DNC(int n,int y,int x) {
	if (n == 1) {
		// 색종이 1장
		cnt[arr[y][x] + 1]++;
		return;
	}
	int yy = y + n;
	int xx = x + n;
	int cnt0 = 0;
	int cnt1 = 0;
	int cnt2 = 0;
	for (int i = y; i < yy; i++) {
		for (int j = x; j < xx; j++) {
			if (arr[i][j] == 0) cnt0++;
			else if (arr[i][j] == 1) cnt1++;
			else cnt2++;
		}
	}
	if (cnt0 == n * n || cnt1 == n * n || cnt2 == n * n) { //색종이 1장
		cnt[arr[y][x] + 1]++;
	}
	else { // 색종이 9등분
		int d = n / 3;
		DNC(n / 3, y, x);
		DNC(n / 3, y, x+d);
		DNC(n / 3, y, x+2*d);
		DNC(n / 3, y+d, x);
		DNC(n / 3, y+d, x+d);
		DNC(n / 3, y+d, x+2*d);
		DNC(n / 3, y+2*d, x);
		DNC(n / 3, y+2*d, x+d);
		DNC(n / 3, y+2*d, x+2*d);
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, j; //for문 변수 -> longlong필요한지 확인
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}
	DNC(n,0,0);
	for (int i = 0; i < 3; i++) {
		cout << cnt[i] << endl;
	}
	return 0;
}