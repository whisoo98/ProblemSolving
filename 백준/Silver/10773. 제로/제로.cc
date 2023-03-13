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

using namespace std;




int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, j; //for문 변수 -> longlong필요한지 확인
	int n; cin >> n;
	stack<int> stk;
	for (i = 1; i <= n; i++) {
		int a; cin >> a;
		if (a == 0) {
			stk.pop();
		}
		else stk.push(a);
	}
	int sum = 0;
	while (!stk.empty()) {
		sum += stk.top();
		stk.pop();
	}
	cout << sum;
	return 0;
}