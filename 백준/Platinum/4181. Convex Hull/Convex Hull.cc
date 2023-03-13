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
#define line pair<pos,pos>

using namespace std;

int ccw(pos p1, pos p2, pos p3) {
	ll c = (p2.first - p1.first)*(p3.second - p1.second)
		- (p2.second - p1.second)*(p3.first - p1.first);
	if (c > 0) return 1;
	else if (c < 0) return -1;
	return 0;
}

void get_ch(deque<pos>& v) {
	sort(v.begin(), v.end());

	deque<pos> U;
	deque<pos> L;

	for (auto it : v) {

		while (U.size() >= 2 && ccw(U[U.size() - 2], U.back(), it) > 0) U.pop_back();
		while (L.size() >= 2 && ccw(L[L.size() - 2], L.back(), it) < 0) L.pop_back();
		U.push_back(it);
		L.push_back(it);
	}

	L.pop_back();
	U.pop_front();
	for (auto it = U.rbegin(); it != U.rend(); it++) {
		L.push_back(*it);
	}
	v = L;
	return;
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, j; //for문 변수 -> longlong필요한지 확인
	int n, m; cin >> n;
	deque<pos> P1;
	
	for (i = 0; i < n; i++) {
		char c;
		ll a, b; cin >> a >> b >> c;
		if (c == 'Y')
		P1.push_back({ a,b });
	}
	
	get_ch(P1);
	cout << P1.size() << endl;
	for (auto it : P1) {
		cout << it.first << " " << it.second << endl;
	}
	return 0;
}