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

set<int> s;
set<int> ALL;
vector<int> ans;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, j; //for문 변수 -> longlong필요한지 확인
	int n; cin >> n;
	for (i = 1; i <= 20; i++) {
		ALL.insert(i);
	}
	for (i = 1; i <= n; i++) {
		string cmd; cin >> cmd;
		if (cmd == "add") {
			int a; cin >> a;
			s.insert(a);
		}
		else if (cmd == "remove") {
			int a; cin >> a;
			if (s.count(a)) {
				s.erase(a);
			}
		}
		else if (cmd == "check") {
			int a; cin >> a;
			cout << s.count(a)<<"\n";
		//	ans.push_back(s.count(a));
		}
		else if (cmd == "toggle") {
			int a; cin >> a;
			if (s.count(a)) {
				s.erase(a);
			}
			else s.insert(a);
		}
		else if (cmd == "all") {
			s = ALL;
		}
		else if (cmd == "empty") {
			s.clear();
		}
	}
	
	return 0;
}