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

ll gcd(ll a, ll b) {
	if (b == 0) return a;
	return gcd(b, a%b);
}
ll lcd(ll a, ll b) {
	ll GCD = gcd(a, b);
	return (a / GCD * b);
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, j; //for문 변수 -> longlong필요한지 확인
	//int n; cin >> n;
	int T; cin >> T;
	while (T--) {
		ll m, n; cin >> m >> n;
		ll x, y; cin >> x >> y;
		ll large, small;
		ll X, Y;
		if (m >= n) {
			large = m;
			X = x;
			small = n;
			Y = y;
		}
		else {
			large = n;
			X = y;
			small = m;
			Y = x;
		}
		ll cnt = 0;
		int chk = 0;
		ll LCD = lcd(m, n);
		for (ll i = large; i <= LCD; i += large) {
			cnt++;
			ll temp = i + X - Y;
			if (temp%small == 0) {
				chk++;
				break;
			}
		}
		//int ans = cnt*
		ll ans=-1;
		if(chk)
			ans = ((ll)cnt*(ll)large + (ll)X)%LCD;
		if (ans ==0 ) ans = LCD;
		cout << ans << endl;
		// X % m == x, X % n == y 인 X를 찾는 문제
		// (X-x)는 m으로 나누어 떨어짐, (X-y)는 n으로 나누어 떨어짐
		
	}
	//cout << gcd(6, 12);
	return 0;
}