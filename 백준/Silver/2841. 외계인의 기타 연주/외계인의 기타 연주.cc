#include <iostream>
#include <algorithm>
#include <functional>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <string>
#include <queue>
#include <stack>
#include <map>
#include <vector>
#include <set>
#include <sstream>

using namespace std;




int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, j; //for문 변수 -> longlong필요한지 확인
	int n, m; cin >> n >> m;
	stack<int> stk[10];
	int sum = 0;
	for (i = 0; i < n; i++) {
		int a, b; cin >> a >> b;
		if (stk[a].empty()) {
			stk[a].push(b);
			sum++;
		}
		else {
			if (b > stk[a].top()) {
				stk[a].push(b);
				sum++;
			}
			else if (b < stk[a].top()) {
				while (!stk[a].empty()) {
					int temp = stk[a].top();
					if (temp > b) {
						stk[a].pop();
						sum++;
					}
					else if (temp < b) {
						stk[a].push(b);
						sum++;
						break;
					}
					else break;
				}
				if (stk[a].empty()) {
					stk[a].push(b);
					sum++;
				}
			}
		}
		//cout << "sum " << sum << endl;
	}
	cout << sum;

	return 0;
}