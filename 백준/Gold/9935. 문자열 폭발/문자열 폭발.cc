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
	string str; cin >> str;
	string bomb; cin >> bomb;
	int len = bomb.size();
	char last = bomb[len - 1];
	int size = str.size();
	stack<char> stk;
	for (i = 0; i < size; i++) {
		stk.push(str[i]);
		if (str[i] == last && len<=stk.size()) {
			string cmp="";
			stack<char>temp;
			for (j = 0; j < len; j++) {
				temp.push(stk.top());
				stk.pop();
			}
			while (!temp.empty()) {
				cmp += temp.top();
				temp.pop();
			}
			if (cmp != bomb) {
				for (j = 0; j < len; j++) {
					//temp.push(cmp[j]);
					stk.push(cmp[j]);
				}
			}
		}	
	}
	if (stk.empty()) cout << "FRULA";
	else {
		stack<char> ans;
		while (!stk.empty()) {
			//cout << stk.top();
			ans.push(stk.top());
			stk.pop();
		}
		while (!ans.empty()) {
			cout << ans.top();
			ans.pop();
		}
	}

	return 0;
}