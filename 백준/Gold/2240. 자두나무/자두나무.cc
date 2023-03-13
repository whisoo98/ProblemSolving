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
#include <cmath>
#include <sstream>


using namespace std;

/*struct type_name {

}srt;*/

//vector <type> vec;
//stack <type> stk;
//queue <type> q;
//string str;
//map <key_type,value_type> m;
int arr[1005];
int dp[1005][1005];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int i, j;//for문변수-->가끔식 long으로
	int n, m; cin >> n >> m;
	for (i = 1; i <= n; i++) {
		int a; cin >> a;
		arr[i] = a % 2;
	}
	for (i = 1; i <= n; i++) {//홀수번 움직이면 내 위치는 0, 짝수번 움직이면 내 위치는 1
		for (j = 0; j < i; j++) {//현재까지 j번 움직였다.
			if (j % 2) {//지금까지 홀수번 움직였다 -> 내 위치는 0
				if (arr[i]) {
					//움직인다면
					dp[i][j + 1] = dp[i - 1][j] + 1;
					//안움직인다면
					dp[i][j] = max(dp[i][j], dp[i - 1][j]);
				}
				else {
					//움직인다면
					dp[i][j + 1] = dp[i - 1][j];
					//안움직인다면
					dp[i][j] = max(dp[i][j], dp[i - 1][j] + 1);
				}
			}

			else {//지금까지 짝수번 움직였다. -> 내 위치는 1
				if (arr[i]) {
					//움직인다면
					dp[i][j + 1] = dp[i - 1][j];
						//안움직인다면
					dp[i][j] = max(dp[i][j], dp[i - 1][j] + 1);
				}
				else {
					//움직인다면
					dp[i][j + 1] = dp[i - 1][j] + 1;
						//안움직인다면
					dp[i][j] = max(dp[i][j], dp[i - 1][j]);
				}
			}
			
		}
	}
	int M = -987;
	//for (i = 0; i <= m; i++) cout << dp[n][i] << endl;
	for (i = 0; i <= m; i++) M = max(M, dp[n][i]);
	cout << M;

	//for(i=0;i<n;i++) {}
	//for(i=0;i<n;i++) { for(j=0;j<n;j++) { } }

	return 0;
}