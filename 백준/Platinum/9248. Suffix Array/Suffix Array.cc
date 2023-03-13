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
#define N 600'000
#define ll long long
#define endl "\n"
#define MID(a,b) (a+b)/2

using namespace std;

char str[N];
int t, n, g[N], tg[N], SA[N], LCP[N],Rank[N];
bool cmp(int x, int y) {
	if (g[x] == g[y]) {
		return g[x + t] < g[y + t];
	}

	return g[x] < g[y];
}

void getSA(const char* str) {
	t = 1;
	n = (int)strlen(str);

	for (int i = 0; i < n; i++) {
		SA[i] = i;
		g[i] = str[i] - 'a';
	}

	while (t <= n) {
		g[n] = -1;
		sort(SA, SA + n, cmp);
		tg[SA[0]] = 0;

		for (int i = 1; i < n; i++) {
			if (cmp(SA[i - 1], SA[i])) {
				tg[SA[i]] = tg[SA[i - 1]] + 1;
			}
			else {
				tg[SA[i]] = tg[SA[i - 1]];
			}
		}
		
		for (int i = 0; i < n; i++) {
			g[i] = tg[i];
		}
		t *= 2;
	}
}

void getLCP(const char* str) {
	for (int i = 0; i < n; i++) {
		Rank[SA[i]] = i;
	}

	int mat = 0;

	for (int i = 0; i < n; i++) {
		int k = Rank[i];
		if (k) {
			int j = SA[k - 1];
			
			while (str[j + mat] == str[i + mat]) mat++;
			
			LCP[k] = mat;
			
			if (mat != 0) mat--;
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, j; //for문 변수 -> longlong필요한지 확인
	
	cin >> str;
	getSA(str);
	getLCP(str);
	
	for (i = 0; i < n; i++) {
		cout << SA[i] + 1 << " ";
	}
	cout << endl;
	for (i = 0; i < n; i++) {
		if (i == 0) {
			cout << "x" << " ";
		}
		else cout << LCP[i] << " ";
	}
	cout << endl;

	return 0;
}