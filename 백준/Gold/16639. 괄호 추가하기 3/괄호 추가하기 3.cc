#include <algorithm>
#include <iostream>
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
#define N 20
#define ll long long
#define endl "\n"
#define MID(a,b) (a+b)/2
#define INF LLONG_MAX
#define MAX 1
#define MIN 0
using namespace std;

char number[N];
char ops[N];
ll dp[N][N][2];

void preProcess(string& exp) {
	for (int i = 0, cnt = 0; i < exp.length(); i++) {
		if (i % 2) {
			ops[cnt++] = exp[i];
		}
		else {
			ops[cnt] = exp[i];
		}
	}
}

ll intervalDP(string& exp, int left, int right, int finding) {
	if (llabs(dp[left][right][finding]) != INF) return dp[left][right][finding];
	if (left == right) return exp[left] - '0';
	ll ret;
	ll L, R;
	if (finding == MAX) {
		ret = -INF;
		for (int i = left + 1; i < right; i += 2) {
			if (exp[i] == '+') {
				L = intervalDP(exp, left, i - 1, MAX);
				R = intervalDP(exp, i + 1, right, MAX);
				ret = max(ret, L + R);
			}
			else if (exp[i] == '-') {
				L = intervalDP(exp, left, i - 1, MAX);
				R = intervalDP(exp, i + 1, right, MIN);
				ret = max(ret, L - R);
			}
			else {
				L = intervalDP(exp, left, i - 1, MAX);
				R = intervalDP(exp, i + 1, right, MAX);
				ret = max(ret, L * R);

				L = intervalDP(exp, left, i - 1, MIN);
				R = intervalDP(exp, i + 1, right, MIN);
				ret = max(ret, L * R);
			}
		}
	}
	else {
		ret = INF;
		for (int i = left + 1; i < right; i += 2) {
			if (exp[i] == '+') {
				L = intervalDP(exp, left, i - 1, MIN);
				R = intervalDP(exp, i + 1, right, MIN);
				ret = min(ret, L + R);
			}
			else if (exp[i] == '-') {
				L = intervalDP(exp, left, i - 1, MIN);
				R = intervalDP(exp, i + 1, right, MAX);
				ret = min(ret, L - R);
			}
			else {
				L = intervalDP(exp, left, i - 1, MAX);
				R = intervalDP(exp, i + 1, right, MAX);
				ret = min(ret, L * R);

				L = intervalDP(exp, left, i - 1, MIN);
				R = intervalDP(exp, i + 1, right, MIN);
				ret = min(ret, L * R);

				L = intervalDP(exp, left, i - 1, MIN);
				R = intervalDP(exp, i + 1, right, MAX);
				ret = min(ret, L * R);

				L = intervalDP(exp, left, i - 1, MAX);
				R = intervalDP(exp, i + 1, right, MIN);
				ret = min(ret, L * R);
			}
		}
	}
	return dp[left][right][finding] = ret;
}

void Solution(string exp) {
	preProcess(exp);
	int len = exp.length();
	int cnt = len / 2;
	for (int i = 0; i <= len; i++) {
		for (int j = 0; j <= len; j++) {
			dp[i][j][MAX] = INF;
			dp[i][j][MIN] = -INF;
		}
	}
	dp[0][len - 1][MAX] = intervalDP(exp, 0, len - 1, MAX);
	dp[0][len - 1][MIN] = intervalDP(exp, 0, len - 1, MIN);
	cout << max(dp[0][len - 1][MAX], dp[0][len - 1][MIN]) << endl;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, j; //for문 변수 -> longlong필요한지 확인
	int n; cin >> n;
	string expression; 
	cin >> expression;
	Solution(expression);
	return 0;
}