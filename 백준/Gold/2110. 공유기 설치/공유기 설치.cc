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
#define N 200'005
#define ll long long
#define endl "\n"
#define MID(a,b) (a+b)/2

using namespace std;


int home[N];

int counting(int dist, int n,int c) {
	int base = home[1];
	int cnt = 1;
	for (int i = 2; i <= n; i++) {
		if (home[i] - base >= dist) {
			base = home[i];
			cnt++;
		}
	}
	return cnt >= c;
}
void Solution(int n, int c) {
	int left = 0, right = 1'000'000'000;
	while (left <= right) {
		int mid = MID(left, right);
		if (counting(mid, n, c)) {
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}
	}
	cout << right << endl;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, j; //for문 변수 -> longlong필요한지 확인
	int n, c; cin >> n >> c;
	for (int i = 0; i < n; i++) {
		cin >> home[i + 1];
	}
	sort(home + 1, home + 1 + n);
	Solution(n, c);
	return 0;
}