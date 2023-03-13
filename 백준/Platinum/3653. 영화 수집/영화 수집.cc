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
#define N 100005
#define ll long long
#define endl "\n"
#define MID(a,b) (a+b)/2

using namespace std;
int arr[2 * N];
int tree[2 * N];
int pos[N];

int sum(int i) {
	int ans = 0;
	while (i > 0) {
		ans += tree[i];
		i -= (i&-i);
	}
	return ans;
}

void update(int i, int diff, int n) {
	while (i <= n) {
		tree[i] += diff;
		i += (i&-i);
	}
}



int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, j; //for문 변수 -> longlong필요한지 확인
	int T; cin >> T;
	while (T--) {
		int n, m; cin >> n >> m;
		for (i = 1; i <= n; i++) {
			pos[i] = m + i;
			//arr[m + i] = 1;
			update(m + i, 1, n + m);
		}
		for (i = 1; i <= m; i++) {
			int a; cin >> a;
			cout << sum(pos[a] - 1) << " ";
			update(pos[a], -1, n + m);
			pos[a] = m + 1 - i;
			update(pos[a], 1, n + m);
			//arr[n+1-i]
		}



		for (i = 1; i <= n; i++) {
			pos[i] = 0;
		}
		for (i = 1; i <= n + m; i++) {
			arr[i] = 0;
			tree[i] = 0;
		}
		cout << endl;
	}

	return 0;
}