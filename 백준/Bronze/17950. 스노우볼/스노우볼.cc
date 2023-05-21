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
#define N 
#define ll long long
#define endl "\n"
#define MID(a,b) (a+b)/2
#define MOD (ll)(1e9+7)
using namespace std;




int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, j; //for문 변수 -> longlong필요한지 확인
	int h, x; cin >> h >> x;
	stack<int> snowballs;
	for (int i = 0; i < h; i++) {
		int a; cin >> a;
		snowballs.push(a);
	}
	ll ans = 0;
	while (snowballs.size()) {
		int snowball = snowballs.top();
		snowballs.pop();
		ans += snowball;
		ans *= x;
		ans %= MOD;
	}
	cout << ans << endl;
	return 0;
}