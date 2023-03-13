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
#define N 200005
#define  ll long long
using namespace std;

ll n, h;
ll ans = INT_MAX; 
ll up[N];
ll down[N];
int C;
vector<int> v;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, j; //for문 변수 -> longlong필요한지 확인
	cin >> n >> h;
	C = (int)n;
	int ans=0;
	for (i = 1; i <= n; i++) {
		if (i % 2) {
			cin >> up[i / 2 + 1];
		}
		else {
			cin >> down[i / 2];
		} 
	}
	sort(up + 1, up + 1 + n / 2);
	sort(down + 1, down + 1 + n / 2);


	for (i = 1; i <= h; i++) {
		int uph = (int)h + 1 - i;
		int sum = 0;
		
		int idx = (lower_bound(up + 1, up + 1 + n / 2, i) - up)-1;
		sum += n/2-idx;

		idx = (lower_bound(down + 1, down + 1 + n / 2, uph) - down)-1;
		sum += n / 2 - idx;
		
		//C = min(C, sum);
		if (C > sum) {
			C = sum;
			ans = 1;
		}
		else if (C == sum) {
			ans++;
		}
	}
	cout << C << " " << ans;
	return 0;
}