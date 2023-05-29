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
#define N 100'005
#define ll long long
#define endl "\n"
#define MID(a,b) (a+b)/2

using namespace std;


int blueray[N];



int counting(ll mid, int n, int m) {
	int cnt = 1;
	ll sum = 0;
	for (int i = 1; i <= n; i++) {
		sum += blueray[i];
		if (sum > mid) {
			sum = blueray[i];
			cnt++;
		}
	}
	//if (sum > mid) cnt++;
	return cnt;
}
int smallest=987654321, biggest;

void Solution(int n, int m) {
	ll left = biggest, right = 1000000000;
	ll ans;
	while (left <= right) {
		ll mid = MID(left, right);
		int cnt = counting(mid, n, m);
		if (cnt > m) {
			left = mid + 1;
		}
		else if (cnt == m) {
			ans = mid;
			right = mid - 1;
		}
		else {
			ans = mid;
			right = mid - 1;
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
	int n, m; cin >> n >> m;
	int M = -1;
	for (int i = 1; i <= n; i++) {
		cin >> blueray[i];
		smallest = min(smallest, blueray[i]);
		biggest = max(biggest, blueray[i]);
		//M = max(M, blueray[i]);
	}
	/*if (n == m) {
		cout << M << endl;
		return 0;
	}*/
	Solution(n, m);
	return 0;
}