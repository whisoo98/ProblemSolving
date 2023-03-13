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
#include <ctime>

using namespace std;


int dp[25][15];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, j; //for문 변수 -> longlong필요한지 확인
	int n; cin >> n;
	if (n == 0) {
		cout << 0;
		return 0;
	}
	if (n >= 1023) {
		cout << -1;
		return 0;
	}
	for (i = 0; i <= 9; i++) {
		dp[1][i] = 1;
	}
	for (i = 0; i <= 9; i++) {
		dp[2][i] = i;
	}
	for (i = 3; i <= 20; i++) {
		for (j = 0; j <= 9; j++) {
			for (int k = 0; k < j; k++) {
				dp[i][j] += dp[i - 1][k];
			}
		}
	}
	int cnt = 0;
	int chk = 0;
	pair<int, int> p;
	queue<int> q;
	for (i = 0; i <= 20; i++) {
		for (j = 0; j <= 9; j++) {
			if (i == 1 && j == 0) continue;
			cnt += dp[i][j];
			if (cnt >= n) {
				chk = 1;
				p = { i,j };
				q.push(j);
				break;
			}
		}
		if (chk) break;
	}
	while (1) {
		int many = p.first;
		int dig = p.second;
		if (many == 1) {
			break;
		}
	
		cnt -= dp[many][dig];
		for (j = 0; j < dig; j++) {
			cnt += dp[many - 1][j];
			if (cnt >= n) {
				p = { many - 1,j };
				q.push(j);
				break;
			}
		}
	}
	//cout << p.first << " " << p.second;
	while (!q.empty()) {
		cout << q.front(); q.pop();
	}
	//cout << cnt;
	return 0;
}