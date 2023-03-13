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
#define N 10005
using namespace std;

int parent[N];
int arr[N];
int visit[N];
int sum;
int Find(int x) {
	if (parent[x] == x) return x;
	return parent[x] = Find(parent[x]);
}

void Union(int x, int y) {
	int X = Find(x);
	int Y = Find(y);
	if (X != Y) {
		if (arr[X] < arr[Y]) {
			if (visit[X] == 0) {
				visit[X] = 1;
			}
			parent[Y] = X;
			visit[Y] = 1;
		}
		else {
			if (visit[Y] == 0) {
				visit[Y] = 1;
			}
			parent[X] = Y;
			visit[X] = 1;
		}
	}
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, j; //for문 변수 -> longlong필요한지 확인
	int n, m, k; cin >> n >> m >> k;
	
	for (i = 1; i <= n; i++) {
		cin >> arr[i];
		parent[i] = i;
	}
	for (i = 1; i <= m; i++) {
		int a, b; cin >> a >> b;
		Union(a, b);
	}
	for (i = 1; i <= n; i++) {
		if (parent[i] == i) {
			sum += arr[i];
		}
	}
	if (sum <= k) cout << sum;
	else cout << "Oh no";
	return 0;
}