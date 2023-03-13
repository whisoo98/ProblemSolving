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

ll arr[N];
ll tree[N];

ll sum(int i) {
	ll ans = 0;
	while (i > 0) {
		ans += tree[i];
		i -= (i&-i);
	}
	return ans;
}

void update(int i, ll diff, int n) {
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

	while (1) {
		int n, k; cin >> n >> k;
		if (cin.eof()) break;
		for (i = 1; i <= n; i++) {
			int a; cin >> a;
			if (a > 0) {
				arr[i] = 2;
			}
			else if (a < 0) {
				arr[i] = 1;
			}
			else {
				arr[i] = -(ll)INT_MAX;
			}
			update(i, arr[i], n);
		}

		for (i = 1; i <= k; i++) {
			char c; cin >> c;
			if (c == 'C') {
				int a; ll b; cin >> a >> b;
				ll diff;

				if (b > 0) {
					if (arr[a] == 2) {
						diff = 0;
					}
					else if (arr[a] == 1) {
						diff = 1;
					}
					else {
						diff = (ll)INT_MAX + 2;
					}
					arr[a] = 2;
				}
				else if (b < 0) {
					if (arr[a] == 2) {
						diff = -1;
					}
					else if (arr[a] == 1) {
						diff = 0;
					}
					else {
						diff = (ll)INT_MAX + 1;
					}
					arr[a] = 1;

				}
				else {
					if (arr[a] == 2) {
						diff = -(ll)INT_MAX - 2;
					}
					else if (arr[a] == 1) {
						diff = -(ll)INT_MAX - 1;
					}
					else {
						diff = 0;
					}
					arr[a] = -(ll)INT_MAX;
				}

				//update(1, n, 1, a, diff);
				update(a, diff, n);
			}
			else {
				int b, c; cin >> b >> c;
				ll ret = sum(c) - sum(b - 1);
				if (ret < 0) cout << "0";
				else if (ret % 2) cout << "-";
				else cout << "+";
			}
		}
		cout << endl;

		for (i = 1; i <= n; i++) {
			arr[i] = 0;
			tree[i] = 0;
		}

	}

	return 0;
}