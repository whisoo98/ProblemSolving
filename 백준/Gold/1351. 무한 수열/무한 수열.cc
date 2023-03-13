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

map<ll, ll> dp;

ll DNC(ll now, ll p, ll q) {
	if (dp.count(now)) return dp[now];
	return dp[now]=DNC(now / p, p, q) + DNC(now / q, p, q);
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, j; //for문 변수 -> longlong필요한지 확인
	ll n, p, q; cin >> n >> p >> q;
	dp[0] = 1;
	cout << DNC(n, p, q) << endl;
	return 0;
}