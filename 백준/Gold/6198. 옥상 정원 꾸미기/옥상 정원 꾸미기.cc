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
#define N 80'005
#define ll long long
#define endl "\n"
#define MID(a,b) (a+b)/2
using namespace std;


stack<pair<int, ll>> roof;
vector<int> height;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, j; //for문 변수 -> longlong필요한지 확인
	int n; cin >> n;
	ll ans = 0;
	for (int i = 0; i < n; i++) {
		int a; cin >> a;
		height.push_back(a);
	}
	roof.push({ INT_MAX,0 });
	for (auto iter = height.rbegin(); iter != height.rend(); iter++) {
		//cout << *iter << endl;
		ll temp = 0;
		while (roof.size()) {
			int rooftop = roof.top().first;
			ll adding = roof.top().second;
			if (rooftop >= *iter) {
				roof.push({ *iter,temp });
				break;
			}
			roof.pop();
			temp += adding + 1;
			ans += adding;
		}
	}
	while (roof.size()) {
		int rooftop = roof.top().first;
		ll adding = roof.top().second;
		roof.pop();
		ans += adding;

	}
	cout << ans << endl;
	return 0;
}