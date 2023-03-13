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
#define N 700
#define ll long long
#define endl "\n"
#define MID(a,b) (a+b)/2

using namespace std;

int arr[N][N];

int DNC(int n, int y, int x) {
	int cnt0 = 0;
	int cnt1 = 0;
	for (int i = y; i < y+n; i++) {
		for (int j = x; j < x+n; j++) {
			if (arr[i][j] == 1) cnt1++;
			else cnt0++;
		}
	}
	if (cnt1 == n * n || cnt0 == n * n) {
		int tmp;
		if (cnt1 > cnt0) tmp = 1;
		else tmp = 0;
		//cout << '(' << tmp << ')';
		return tmp;
	}
	else {
		int d = n / 2;
		cout << "(";
		int lu = DNC(n / 2, y, x);
		if (lu != -1) cout << lu;

		int ru = DNC(n / 2, y, x + d);
		if (ru != -1) cout << ru;

		int ld = DNC(n / 2, y + d, x);
		if (ld != -1) cout << ld;

		int rd = DNC(n / 2, y + d, x + d);
		if (rd != -1) cout << rd;

		cout << ')';
		return -1;
	}
}

int main()
{
	//ios_base::sync_with_stdio(false);
	//cin.tie(NULL);
	//cout.tie(NULL);

	int i, j; //for문 변수 -> longlong필요한지 확인
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			char c; cin >> c;
			arr[i][j] = c - '0';
		}
	}
	
	int all = DNC(n, 0, 0);
	if (all != -1) {
		//cout << "(" << all << ")";
		cout << all;
	}
	return 0;
}