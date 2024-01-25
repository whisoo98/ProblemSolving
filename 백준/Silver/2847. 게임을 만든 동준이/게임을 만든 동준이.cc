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


int lv[N];

int decreaseLv(int n) {
	int ret = 0;
	int before= lv[n];
	for (int i = n-1; i > 0; i--) {
		int now = lv[i];
		if (now >= before) {
			ret += abs(now - before) + 1;
			now -= (abs(now - before) + 1);
		}
		before = now;
	}
	return ret;
}

void Solution(int n) {
	int ans = decreaseLv(n);
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
		cin >> lv[i];
	}
	Solution(n);
	return 0;
}