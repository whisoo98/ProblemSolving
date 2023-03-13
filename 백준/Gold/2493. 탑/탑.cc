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

vector<int> ans;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int i, j; //for문 변수 -> long long필요한지 확인
	int n; cin >> n;
	ans.resize(n + 5);
	stack<pair<int,int>> stk;
	for (i = 1; i <= n; i++) {
		int a; cin >> a;
		stk.push({ a,i });
	}
	//stack<int> ans;
	while (!stk.empty()) {
		int top = stk.top().first;
		int pos = stk.top().second;
		stk.pop();
		stack<pair<int, int>>q; q.push({ top,pos });
		while (!stk.empty() && !q.empty()) {
			top = q.top().first;
			pos = q.top().second;
			if (stk.top().first < top) {
				q.push(stk.top());
				
				stk.pop();
			}
			else {
				//ans.push(stk.top().second);
				ans[pos] = stk.top().second;
				q.pop();
				//top = stk.top().first;
				//pos = stk.top().second;
				
			}
		}
	}
	for (int i = 1; i <= n;i++) {
		cout << ans[i]<<" ";
	}
	return 0;
}