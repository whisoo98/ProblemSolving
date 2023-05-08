#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <functional>
#include <stdlib.h>
#include <string>
#include <queue>
#include <stack>
#include <map>
#include <climits>
#include <cstring>
#define N 10'005
#define ll long long
using namespace std;

// including i-th app, 
// if I pay the amount of cost j,
// I can afford dp[i][j] memory.
ll dp[105][N];
ll memory[105];
int cost[105];

void knapsack(int n, ll m) {
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < N; j++) {
			if (j >= cost[i]) {
				if (dp[i - 1][j] >= dp[i - 1][j - cost[i]] + memory[i]) {
					dp[i][j] = dp[i - 1][j];
				}
				else {
					dp[i][j] = dp[i - 1][j - cost[i]] + memory[i];
				}
			}
			else {
				dp[i][j] = dp[i - 1][j];
			}
		}
	}
}

void Solution(int n, ll m) {
	knapsack(n, m);
	int ans = 987654321;
	for (int i = 0; i < N; i++) {
		if (dp[n][i] >= m) {
			cout << i << endl;
			break;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n; ll m; cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> memory[i];
	}

	for (int i = 1; i <= n; i++) {
		cin >> cost[i];
	}
	Solution(n, m);
	return 0;
}