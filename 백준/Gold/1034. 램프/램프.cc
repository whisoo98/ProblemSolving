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
#define N 55
#define ll long long
#define endl "\n"
#define MID(a,b) (a+b)/2

using namespace std;

int arr[N][N];
int row_visit[N];
int row_zero_cnt[N];

void cmp_row(int y, int x) {
	for (int i = 1; i <= y; i++) {
		if (row_visit[i]) continue;
		row_visit[i] = 1;
		for (int cmp_i = i + 1; cmp_i <= y; cmp_i++) {
			if (row_visit[cmp_i]) continue;
			int cmp = 0;
			for (int j = 1; j <= x; j++) {
				if (arr[i][j] == arr[cmp_i][j]) cmp++;
				else break;
			}
			if (cmp == x) {
				row_visit[cmp_i] = -1;
				row_visit[i] += 1;
			}
		}
		int zero_cnt = 0;
		for (int j = 1; j <= x; j++) {
			if (arr[i][j] == 0) zero_cnt++;
		}
		row_zero_cnt[i] = zero_cnt;
	}
}

int switch_lamp(int y, int x, int k) {
	int ans = 0;
	for (int i = 1; i <= y; i++) {
		if (row_visit[i] == -1) continue;
		int zero_cnt = row_zero_cnt[i];
		int temp_k = k;
		temp_k -= zero_cnt;
		if (temp_k >= 0 && temp_k % 2 == 0) { 
			ans = max(ans, row_visit[i]);
		}
	}
	return ans;
}

void Solution(int y, int x, int k) {
	cmp_row(y, x);
	int ans = switch_lamp(y, x, k);
	cout << ans << endl;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int y, x; cin >> y >> x;
	for (int i = 1; i <= y; i++) {
		string s; cin >> s;
		for (int j = 1; j <= x; j++) {
			arr[i][j] = s[j - 1] - '0';
		}
	}
	int k; cin >> k;
	Solution(y, x, k);

	return 0;
}