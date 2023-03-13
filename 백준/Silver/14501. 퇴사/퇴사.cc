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
//#include <ctime>

using namespace std;

int time[20];
int price[20];
//int dp[30][20];
int dp[30][30][10];
int dp2[30];


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, j, k; //for문 변수 -> longlong필요한지 확인
	//while (1) {
		int n; cin >> n;
		for (i = 1; i <= n; i++) {
			cin >> time[i] >> price[i];
		}
		
		for (i = 1; i <= n + 1; i++) {
			for (j = 1; j <= n + 1; j++) {
				if (j >= i + time[i]) {
					for (k = 0; k <= 5; k++) {
						if (k == time[i]) {
							dp[i][j][k] = max(dp[i - 1][j][k + 1], dp[i][j - time[i]][0] + price[i]);
						}
						else if (k == 0) {
							dp[i][j][k] = max(dp[i - 1][j][k + 1], dp[i - 1][j][0]);
						}
						else {
							dp[i][j][k] = dp[i - 1][j][k + 1];
						}
					}
				}
				else {
					for (k = 0; k <= 5; k++) {
						if (k == 0) {
							dp[i][j][k] = max(dp[i - 1][j][k + 1], dp[i - 1][j][0]);
						}
						else {
							dp[i][j][k] = dp[i - 1][j][k + 1];
						}
					}
				}
			}

		}
		int M = -1;
		for (i = 1; i <= n+1; i++) {
			M = max(M, dp[n + 1][i][0]);
		}
		cout << M;
		/*for (i = 1; i <= n + 1; i++) {
			time[i] = 0; price[i] = 0;
			for (j = 1; j <= n + 1; j++) {
				for(int k=0;k<=10;k++)
					dp[i][j][k] = 0;
			}
		}*/
	//}
	return 0;
}