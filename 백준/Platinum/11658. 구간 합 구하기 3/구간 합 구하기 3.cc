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
#define N 1030
#define ll long long
#define endl "\n"
#define MID(a,b) (a+b)/2

using namespace std;

ll tree[N][N];
ll arr[N][N];

ll sum(int i, int j) {
	ll ans = 0;
	while (i > 0) {
		int temp = j;
		while (temp > 0) {
			ans += tree[i][temp];
			temp -= (temp&-temp);
		}
		i -= (i&-i);
	}
	return ans;
}

void update(int i, int j, ll diff, int n) {
	while (i <= n) {
		int temp = j;
		while (temp <= n) {
			tree[i][temp] += diff;
			temp += (temp&-temp);
		}
		i += (i&-i);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, j; //for문 변수 -> longlong필요한지 확인
	int n, m; cin >> n >> m;
	
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++) {
			cin >> arr[i][j];
			update(i, j, arr[i][j], n);
		}
	}

	for (i = 1; i <= m; i++) {
		int w; cin >> w;
		if (!w) {//update
			int x, y; cin >> x >> y;
			ll del; cin >> del;
			ll diff; diff = del - arr[x][y];
			arr[x][y] = del;
			update(x, y, diff, n);
		}
		else {//sum
			int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
			//cout << sum(x2, y2) << endl;
			//cout << sum(x1 - 1, y2) << endl;
			//cout << sum(x2, y1 - 1) << endl;
			//cout << sum(x1 - 1, y1 - 1) << endl;
			cout << sum(x2, y2) - sum(x1 - 1, y2) - sum(x2, y1 - 1) + sum(x1 - 1, y1 - 1) << endl;
		}
	}
	return 0;
}