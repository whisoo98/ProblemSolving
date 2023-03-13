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

map<ll, int> m;
int cnt;
ll colatz(ll a) {
	m[a] = cnt++;
	if (a == 1) return a;
	if (a % 2 == 0) {
		return colatz(a / 2);
	}
	else {
		return colatz(3 * a + 1);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//cout.tie(NULL);

	int i, j; //for문 변수 -> longlong필요한지 확인
	//int n; cin >> n;
	while (1) {
		ll a, b; cin >> a >> b;
		ll save_b = b;
		if (a + b == 0) return 0;
		colatz(a);
		int count = 0;
		while (1) {
			if (m.find(b) != m.end()) {
				break;
			}
			if (b % 2 == 0) {
				b /= 2;
			}
			else {
				b = 3 * b + 1;
			}
			count++;
		}
		printf("%lld needs %d steps, %lld needs %d steps, they meet at %lld\n", a, m[b], save_b, count, b);
		cnt = 0;
		m.clear();
	}

	return 0;
}