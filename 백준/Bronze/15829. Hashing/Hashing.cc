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
#define MOD 1234567891
#define R 31
using namespace std;




int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, j; //for문 변수 -> longlong필요한지 확인
	int n; cin >> n;
	ll ans = 0;
	for (i = 1; i <= n; i++) {
		char c; cin >> c;
		ll mul = 1;
		for (j = 1; j < i; j++) {
			mul *= R;
			mul %= MOD;
		}
		ans += mul * (c - 'a' + 1);
		ans %= MOD;
	}
	cout << ans;
	return 0;
}