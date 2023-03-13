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
#define N 1000005
#define ll long long
#define endl "\n"
#define MID(a,b) (a+b)/2

using namespace std;

int parent[N];
int cnt[N];
int Find(int x) {
	if (x == parent[x]) return x;
	return parent[x] = Find(parent[x]);
}

void Union(int x, int y) {
	int X = Find(x);
	int Y = Find(y);
	if (X != Y) {
		parent[X] = Y;
		cnt[Y] += cnt[X];
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int i, j; //for문 변수 -> longlong필요한지 확인
	int n; cin >> n;
	for (i = 1; i <= N; i++) {
		parent[i] = i;
		cnt[i] = 1;
	}
	for (i = 1; i <= n; i++) {
		char cmd; cin >> cmd;
		if (cmd == 'I') {
			int a, b; cin >> a >> b;
			Union(a, b);
		}
		else {
			int a; cin >> a;
			cout << cnt[Find(a)]<<endl;
		}
	}

	return 0;
}