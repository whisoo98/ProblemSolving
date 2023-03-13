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
#define N 10'005
#define ll long long
#define endl "\n"
#define MID(a,b) (a+b)/2

using namespace std;


vector<pair<int,int>> edge[N];
int dp[N];

int Solution(int n) {
	if (dp[n] != -1) return dp[n];
	dp[n] = 0;
	vector<int> tmp(3, 0);
	for (auto it : edge[n]) {
		int next = it.first;
		int len = it.second;
		int temp = 0;
		temp = Solution(next);
		tmp[2] = temp + len;
		sort(tmp.begin(), tmp.end(), greater<int>());
	}
	dp[n] = tmp[0] + tmp[1];
	return tmp[0];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, j; //for문 변수 -> longlong필요한지 확인
	int n; cin >> n;
	for (int i = 1; i <= n; i++) dp[i] = -1;
	for (int i = 0; i < n-1; i++) {
		//dp[i + 1] = -1;
		int a, b, c;
		cin >> a >> b >> c;
		edge[a].push_back({ b, c });
	}
	Solution(1);
	int m = -1;
	for (int i = 1; i <= n; i++) {
		m = max(m, dp[i]);
	}
	cout << m;
	return 0;
}