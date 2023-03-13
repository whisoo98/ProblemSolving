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
int pos[N];

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
	int n; cin >> n;
	for (i = 1; i <= n; i++) {
		int a; cin >> a;
		pos[a] = i;
		update(i, 1, n);
	}
	i = 1; j = n;
	for (int T = 1; T <= n; T++) {
		if (T % 2) {
			cout << sum(pos[i] - 1) << endl;
			update(pos[i++], -1, n);

		}
		else {
			cout << sum(n) - sum(pos[j]) << endl;
			update(pos[j--], -1, n);

		}
		//cout << sum(pos[T]-1)<<endl;
		//pos[T] = 0;
	}
	return  0;
}