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

vector<int> v;
int n;
int ans[20];
void dfs(int cnt, int level) {
	if (level == 6) {
		for (int i = 0; i < 6; i++) {
			cout << ans[i] << " ";
		}
		cout << "\n";
		return;
	}
	if (cnt >= n) {
		return;
	}
	else if (cnt == n - 1) {
		ans[level] = v[cnt];
		dfs(cnt + 1, level + 1);
		return;
	}
	else {
		ans[level] = v[cnt];
		dfs(cnt + 1, level + 1);
		dfs(cnt + 1, level);
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, j; //for문 변수 -> longlong필요한지 확인
	while (1) {
		 cin >> n;
		if (!n) return 0;
		for (i = 0; i < n; i++) {
			int a; cin >> a;
			v.push_back(a);
		}
		dfs(0,0);
		v.clear();
		cout << "\n";
	}

	return 0;
}