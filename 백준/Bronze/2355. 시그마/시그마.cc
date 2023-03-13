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
#define SUM(n) n*(n+1)/2
using namespace std;




int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, j; //for문 변수 -> longlong필요한지 확인
	ll a, b; cin >> a >> b;
	ll m = min(a, b);
	ll M = max(a, b);
	//cout << m << " " << M << endl;
	ll ans;
	if (m <= 0 && M <= 0) {
		M = -M; m = -m;
		ans = SUM(m) - SUM(M) + M;
		cout << -ans;
	}
	else if (m <= 0 && M>0) {
		ll temp;
		m = -m;
		temp = SUM(m);
		temp = -temp;
		ans = SUM(M);
		ans += temp;
		cout << ans;
	}
	else {
		ans = SUM(M) - SUM(m) + m;
		cout << ans;
	}
	return 0;
}