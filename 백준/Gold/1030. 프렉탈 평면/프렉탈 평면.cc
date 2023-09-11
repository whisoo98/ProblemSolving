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
#define N 10
#define ll long long
#define endl "\n"
#define MID(a,b) (a+b)/2

using namespace std;


int arr[N][N];

ll calcXPoint(ll s, ll n, ll x) {
	ll temp = x;
	/*while (x / n) {
		x /= n;
		temp = x;
	}*/
	return temp % n;
}

ll calcYPoint(ll s, ll n, ll y) {
	ll temp = y;
	/*while (y / n) {
		y /= n;
		temp = y;
	}*/
	return temp % n;
}

ll inverseXPoint(ll s, ll n, ll x) {
	return x / n;
}

ll inverseYPoint(ll s, ll n, ll y) {
	return y / n;
}

int Fractal(ll s, ll n, ll k, ll y, ll x) {
	if (s == 1) {
		return arr[y][x];
	}
	else {
		ll inverseY = inverseYPoint(s, n, y);
		ll inverseX = inverseXPoint(s, n, x);
		int ret = Fractal(s - 1, n, k, inverseY, inverseX);
		if (ret == 1) {
			return ret;
		}
		else {
			return arr[calcYPoint(s, n, y)][calcXPoint(s, n, x)];
		}
	}
}

void Solution(ll s, ll n, ll k, ll y1, ll y2, ll x1, ll x2) {
	if (s == 0) {
		cout << 0;
	}
	else {
		for (ll i = y1; i <= y2; i++) {
			for (ll j = x1; j <= x2; j++) {
				cout << Fractal(s, n, k, i, j);
			}
			cout << endl;
		}
	}
}







int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, j; //for문 변수 -> longlong필요한지 확인
	ll s, n, k, y1, y2, x1, x2;
	cin >> s >> n >> k >> y1 >> y2 >> x1 >> x2;
	
	if (n % 2 == 1) {
		for (int i = n / 2 - k / 2; i <= n / 2 + k / 2; i++) {
			for (int j = n / 2 - k / 2; j <= n / 2 + k / 2; j++) {
				arr[i][j] = 1;
			}
		}
	}
	else{
		for (int i = n / 2 - k / 2; i < n / 2 + k / 2; i++) {
			for (int j = n / 2 - k / 2; j < n / 2 + k / 2; j++) {
				arr[i][j] = 1;
			}
		}
	}
	
	Solution(s, n, k, y1, y2, x1, x2);
	return 0;
}