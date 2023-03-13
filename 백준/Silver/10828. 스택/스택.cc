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
	int n; cin >> n;
	stack<int> stk;
	while (n--) {
		string cmd; cin >> cmd;
		if (cmd == "push") {
			int a; cin >> a;
			stk.push(a);
		}
		else if (cmd == "pop") {
			if (!stk.empty()) {
				cout << stk.top() << "\n";
				stk.pop();
			}
			else cout << "-1\n";
		}
		else if (cmd == "size") {
			cout << stk.size() << "\n";
		}
		else if (cmd == "empty") {
			cout << stk.empty() << "\n";
		}
		else if (cmd == "top") {
			if (!stk.empty()) {
				cout << stk.top() << "\n";
			}
			else cout << "-1\n";
		}
	}

	return 0;
}