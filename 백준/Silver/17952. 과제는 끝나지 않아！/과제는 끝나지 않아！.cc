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

using namespace std;




int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, j; //for문 변수 -> longlong필요한지 확인
	int n; cin >> n;
	stack<tuple<int, int, int>> assignment;
	int as_done = 0;
	int as_score = 0;
	int as_takes = 987654321;
	int ans = 0;
	for (int i = 0; i < n; i++) {
		int cmd; cin >> cmd;
		if (cmd) {
			int score, takes; cin >> score >> takes;
			assignment.push({ as_score,as_takes,as_done });
			as_done = 0;
			as_score = score;
			as_takes = takes;
		}
		as_done++;
		if (as_done == as_takes) {
			ans += as_score;
			as_score = get<0>(assignment.top());
			as_takes = get<1>(assignment.top());
			as_done = get<2>(assignment.top());
			assignment.pop();
		}
	}
	cout << ans << endl;
	return 0;
}