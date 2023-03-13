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
#define N 300005
using namespace std;

int parent[N];

int Find(int x) {
	if (parent[x] == x) return x;
	return parent[x] = Find(parent[x]);
}

void Union(int x, int y) {
	int X = Find(x);
	int Y = Find(y);
	if (X != Y) {
		parent[X] = Y;
	}
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, j; //for문 변수 -> longlong필요한지 확인
	int n; cin >> n;
	for (i = 1; i <= n; i++) {
		parent[i] = i;
	}
	for (i = 1; i <= n - 2; i++) {
		int a, b; cin >> a >> b;
		Union(a, b);
	}
	int base = Find(1);
	int cmp;
	for (i = 2; i <= n; i++) {
		cmp = Find(i);
		if (base != cmp) break;
	}
	cout << base << " " << cmp;
	return 0;
}