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

int t;
int SA[N];
int g[N];
int tg[N];

bool cmp(int x, int y) {

	if (g[x] == g[y]) {
		return g[x + t] < g[y + t];
	}
	return g[x] < g[y];
}

void getSA(string s) {
	int len = s.length();
	t = 1;
	int i;
	for (i = 0; i < len; i++) {
		SA[i] = i;
		g[i] = s[i] - 'a';
	}

	while (t <= len) {
		g[len] = -1;
		sort(SA, SA + len, cmp);
		tg[SA[0]] = 0;

		for (i = 1; i < len; i++) {
			if (cmp(SA[i - 1], SA[i])) {
				tg[SA[i]] = tg[SA[i - 1]] + 1;
			}
			else tg[SA[i]] = tg[SA[i - 1]];
		}

		for (i = 0; i < len; i++) g[i] = tg[i];
		t *= 2;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, j; //for문 변수 -> longlong필요한지 확인
	string s; cin >> s;
	getSA(s);
	int len = s.length();
	for (i = 0; i < len; i++) {
		cout << SA[i] << endl;
	}

	return 0;
}