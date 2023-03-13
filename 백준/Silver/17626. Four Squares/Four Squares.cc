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
#define N 50'005
#define ll long long
#define endl "\n"
#define MID(a,b) (a+b)/2

using namespace std;

vector<int>square;

int dp[N];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, j; //for문 변수 -> longlong필요한지 확인
	int n; cin >> n;
	for (int i = 1; i < N; i++) dp[i] = 987654321;
	for (int i = 1; i <= sqrt(N); i++) {
		square.push_back(i*i);
		dp[i*i] = 1;
	}
	for (int i = 2; i <= n; i++) {
		for (auto it : square) {
			if (it > i) break;
			dp[i] = min(dp[i], dp[i - it]+1);
		}
	}
	cout << dp[n];
	return 0;
}