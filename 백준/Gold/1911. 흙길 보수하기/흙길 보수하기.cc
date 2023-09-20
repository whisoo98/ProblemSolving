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
#define N 1'000'000'005
#define ll long long
#define endl "\n"
#define MID(a,b) (a+b)/2

using namespace std;

vector<pair<int, int>> v;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, j; //for문 변수 -> longlong필요한지 확인
	int n, l; cin >> n >> l;
	for (int i = 0; i < n; i++) {
		int a, b; cin >> a >> b;
		v.push_back({ a, b });
	}
	sort(v.begin(), v.end());
	int ans = 0;
	int before_end = -1;
	for (auto it : v) {
		int st = max(before_end, it.first);
		int i;
		for (i = st; i < it.second; i += l) {
			ans += 1;
		}
		before_end = i;
	}
	cout << ans << endl;

	return 0;
}