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
#define N 1'000'005
#define ll long long
#define endl "\n"
#define MID(a,b) (a+b)/2

using namespace std;


int arr[N];
int ans[N];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, j; //for문 변수 -> longlong필요한지 확인
	int n; cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	stack<int> stk;
	stack<int> idx;
	for (int i = n; i > 0; i--) {
		while (1) {
			if (stk.empty()) {
				stk.push(arr[i]);
				idx.push(i);
				ans[i] = -1;
				break;
			}
			if (stk.top()<=arr[i]) {
				stk.pop();
				idx.pop();
			}
			else {
				ans[i] = stk.top();
				stk.push(arr[i]);
				idx.push(i);
				break;
			}
		}
	}
	/*while (stk.size()) {
		int index = idx.top();
		ans[index] = -1;
		idx.pop();
		stk.pop();
	}*/
	for (int i = 1; i <= n; i++) {
		cout << ans[i] << " ";
	}
	cout << endl;
	return 0;
}