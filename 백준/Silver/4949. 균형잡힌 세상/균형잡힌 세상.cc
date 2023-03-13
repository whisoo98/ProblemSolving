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

bool check(char c) {
	if (c == '(' || c == ')' || c == '[' || c == ']') return true;
	return false;
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, j; //for문 변수 -> longlong필요한지 확인
	while (1) {
		string s;
		stack<char> stk;
		int chk = 0;
		getline(cin, s);
		if (s.length() == 1 && s[0] == '.') break;
		int len = s.length();
		for (i = 0; i < len; i++) {
			if (check(s[i])) {
				if (s[i] == '(' || s[i] == '[') {
					stk.push(s[i]);
				}
				else if (s[i] == ')') {
					if (stk.empty()) {
						chk = 1;
						break;
					}
					else {
						if (stk.top() == '(') {
							stk.pop();
						}
						else {
							chk = 1;
							break;
						}
					}
				}
				else if (s[i] == ']') {
					if (stk.empty()) {
						chk = 1;
						break;
					}
					else {
						if (stk.top() == '[') {
							stk.pop();
						}
						else {
							chk = 1;
							break;
						}
					}
				}
			}
		}
		if (!stk.empty()) chk = 1;
		if (chk == 1) {
			cout << "no\n";
		}
		else cout << "yes\n";
	}

	return 0;
}