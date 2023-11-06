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
#define N 100'005
#define ll long long
#define endl "\n"
#define MID(a,b) (a+b)/2
#define UP 1
#define LEFT 2
#define DOWN 3
#define RIGHT 4
#define INF 987654321
using namespace std;


int ddr[N];
int ddr_dp[N][5][5];
int add_power[5][5] = { // from [first_idx] to [second_idx]
	{-1,2,2,2,2},
	{-1,1,3,4,3}, // UP 
	{-1,3,1,3,4}, // LEFT
	{-1,4,3,1,3}, // DOWN
	{-1,3,4,3,1} // RIGHT
};

void DDR(int now, int n) {
	ddr_dp[0][0][0] = 0;
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < 5; j++) {
			for (int k = 0; k < 5; k++) {
				ddr_dp[i][ddr[i]][j] = min(ddr_dp[i][ddr[i]][j], ddr_dp[i - 1][k][j] + add_power[k][ddr[i]]);
			}
			for (int k = 0; k < 5; k++) {
				ddr_dp[i][j][ddr[i]] = min(ddr_dp[i][j][ddr[i]], ddr_dp[i - 1][j][k] + add_power[k][ddr[i]]);
			}
		}
		//if (ddr[i] == UP) {
		//	// move left foot
		//	for (int j = 0; j < 5; j++) {
		//		for (int k = 0; k < 5; k++) {
		//			ddr_dp[i][UP][j] = min(ddr_dp[i][UP][j], ddr_dp[i - 1][k][j] + add_power[j][UP]);
		//		}
		//	}

		//	// move right foot
		//	for (int j = 0; j < 5; j++) {
		//		ddr_dp[i][j][UP] = min(ddr_dp[i][j][UP], ddr_dp[i - 1][j][j] + add_power[j][UP]);
		//	}
		//}
		//else if (ddr[i] == LEFT) {
		//	// move left foot
		//	for (int j = 0; j < 5; j++) {
		//		ddr_dp[i][LEFT][j] = min(ddr_dp[i][LEFT][j], ddr_dp[i - 1][j][j] + add_power[j][LEFT]);
		//	}

		//	// move right foot
		//	for (int j = 0; j < 5; j++) {
		//		ddr_dp[i][j][LEFT] = min(ddr_dp[i][j][LEFT], ddr_dp[i - 1][j][j] + add_power[j][LEFT]);
		//	}
		//}
		//else if (ddr[i] == RIGHT) {
		//	// move left foot
		//	for (int j = 0; j < 5; j++) {
		//		ddr_dp[i][RIGHT][j] = min(ddr_dp[i][RIGHT][j], ddr_dp[i - 1][j][j] + add_power[j][RIGHT]);
		//	}

		//	// move right foot
		//	for (int j = 0; j < 5; j++) {
		//		ddr_dp[i][j][RIGHT] = min(ddr_dp[i][j][RIGHT], ddr_dp[i - 1][j][j] + add_power[j][RIGHT]);
		//	}
		//}
		//else if (ddr[i] == DOWN) {
		//	// move left foot
		//	for (int j = 0; j < 5; j++) {
		//		ddr_dp[i][DOWN][j] = min(ddr_dp[i][DOWN][j], ddr_dp[i - 1][j][j] + add_power[j][DOWN]);
		//	}

		//	// move right foot
		//	for (int j = 0; j < 5; j++) {
		//		ddr_dp[i][j][DOWN] = min(ddr_dp[i][j][DOWN], ddr_dp[i - 1][j][j] + add_power[j][DOWN]);
		//	}
		//}
		/*for (int k = 0; k < 5; k++) {
			for (int j = 0; j < 5; j++) {
				cout << ddr_dp[i][k][j] << " ";
			}
			cout << endl;
		}
		cout << endl;*/
	}
}

void Solution(int n) {
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j < 5; j++) {
			for (int k = 0; k < 5; k++) {
				ddr_dp[i][j][k] = INF;
			}
		}
	}
	DDR(0,n);
	int ret = INF;
	
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			ret = min(ret, ddr_dp[n - 1][i][j]);
		}
	}
	cout << ret << endl;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, j; //for문 변수 -> longlong필요한지 확인
	i = 1;
	while (1) {
		cin >> ddr[i];
		if (ddr[i] == 0) {
			break;
		}
		i++;
	}
	if (i == 1) {
		cout << 0 << endl;
		return 0;
	}
	Solution(i);
	return 0;
}