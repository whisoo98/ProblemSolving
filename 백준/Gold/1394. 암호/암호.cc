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
#define MOD 900528

using namespace std;

ll dividePower(int n, int len) {
	if (n == 0) return 1;
	if (n == 1) return len;
	if (n % 2 == 0) {
		return ((dividePower(n / 2, len) % MOD) *(dividePower(n / 2, len) % MOD)) % MOD;
	}
	else {
		return ((((dividePower(n / 2, len) % MOD) *(dividePower(n / 2, len) % MOD)) % MOD) * len) % MOD;
	}
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string s; cin >> s;
	string pwd; cin >> pwd;
	int len = s.length();

	reverse(pwd.begin(), pwd.end());
	ll ans = 0;
	int i = 0;
	for (auto it : pwd) {
		ll power = dividePower(i, len);
		ans += (s.find(it)+1) * power;
		i++;
		ans %= MOD;
	}
	cout << ans << endl;
	return 0;
}