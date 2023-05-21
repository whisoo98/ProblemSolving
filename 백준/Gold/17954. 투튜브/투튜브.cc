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
#define N 10'005
#define ll long long
#define endl "\n"
#define MID(a,b) (a+b)/2

using namespace std;




int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, j; //for문 변수 -> longlong필요한지 확인
	int n; cin >> n;
	if (n == 1) {
		cout << 2 << endl;
		cout << 1 << endl << 2 << endl;
		return 0;
	}
	ll tot = (1 + 2 * n)*n;
	stack<int> stk1, stk2;
	stk1.push(2*n);
	stk2.push(2 * n - 2);
	for (int i = 1; i <= n-2; i++) {
		stk1.push(i);
		stk2.push(i + (n - 2));
	}
	stk1.push(2 * n - 1);
	stk2.push(2 * n - 3);
	int t = 0;
	ll ans = 0;
	while (stk1.size() || stk2.size()) {
		int fruit;
		;
		if (stk2.size()) {
			fruit = stk2.top();
			stk2.pop();
		}
		else {
			fruit = stk1.top();
			stk1.pop();
		}
		ans += tot * t;
		tot -= fruit;
		t++;
	}
	cout << ans << endl;
	stk1.push(2 * n);
	stk2.push(2 * n - 2);
	for (int i = 1; i <= n - 2; i++) {
		stk1.push(i);
		stk2.push(i + (n - 2));
	}
	stk1.push(2 * n - 1);
	stk2.push(2 * n - 3);
	while (stk1.size()) {
		int fruit = stk1.top();
		stk1.pop();
		cout << fruit << " ";
	}
	cout << endl;
	while (stk2.size()) {
		int fruit = stk2.top();
		stk2.pop();
		cout << fruit << " ";
	}
	cout << endl;
	return 0;
}