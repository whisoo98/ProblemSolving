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
#define N 
#define ll long long
#define endl "\n"
#define MID(a,b) (a+b)/2

using namespace std;

int DNC(int n, int r, int c) {
	int ans = 0;
	if (n == 1) {
		return r * 2 + c;
	}
	if (pow(2, n - 1) > r) {
		if (pow(2, n - 1) > c) {
			ans += DNC(n - 1, r, c);
		}
		else {
			ans += pow(2, n - 1)*pow(2, n - 1);
			ans += DNC(n - 1, r, c - pow(2, n - 1));
		}
	}
	else {
		if (pow(2, n - 1) > c) {
			ans += pow(2, n - 1)*pow(2, n - 1) * 2;
			ans += DNC(n - 1, r - pow(2, n - 1), c);
		}
		else {
			ans += pow(2, n - 1)*pow(2, n - 1) * 3;
			ans += DNC(n - 1, r - pow(2, n - 1), c - pow(2, n - 1));
		}
	}
	return ans;
}


void Solution(int n, int r, int c) {
	int ans = DNC(n, r, c);
	cout << ans;
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, j; //for문 변수 -> longlong필요한지 확인
	int n, r, c; cin >> n >> r >> c;
	Solution(n, r, c);

	return 0;
}