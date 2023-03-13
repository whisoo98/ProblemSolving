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
#define pi pair<ll,ll>
#define pos pi
#define line pair<pi,pi>
#define f first
#define s second
using namespace std;

pi p[5];
line L[5];

ll ccw(pos p1, pos p2, pos p3) {
	ll t = (p2.f - p1.f)*(p3.s - p1.s)
		- (p2.s - p1.s)*(p3.f - p1.f);
	if (t > 0) return 1;
	else if (t == 0) return 0;
	else return -1;
}

ll ccw(pi p1, pi p2) {
	return (p2.f - p1.f)*(p2.s - p1.s) 
		- (p2.s - p1.s)*(p2.f - p1.f);
}

int is_cross(line l1, line l2) {
	pos P = l1.f, Q = l1.s, R = l2.f, S = l2.s;
	if (P == R || P == S || Q == R || Q == S) return 0;

	ll res1 = ccw(P, Q, R)*ccw(P, Q, S);
	ll res2 = ccw(R, S, P)*ccw(R, S, Q);
	if (res1 <= 0 && res2 <= 0) {
		if ((P.f > R.f&&P.f > S.f&&Q.f > R.f&&Q.f > S.f) ||
			(P.f < R.f&&P.f < S.f&&Q.f < R.f&&Q.f < S.f) ||
			(P.s > R.s&&P.s > S.s&&Q.s > R.s&&Q.s > S.s) ||
			(P.s < R.s&&P.s < S.s&&Q.s < R.s&&Q.s < S.s))
		{
			return -1;
		}
		else return 1;
	}
	return -1;
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, j; //for문 변수 -> longlong필요한지 확인
	for (i = 0; i < 2; i++) {
		
			ll a, b, c, d; cin >> a >> b >> c >> d;
			L[i] = { {a,b},{c,d} };
		
	}
	if (is_cross(L[0], L[1]) >= 0) {
		cout << 1;
	}
	else cout << 0;

	return 0;
}