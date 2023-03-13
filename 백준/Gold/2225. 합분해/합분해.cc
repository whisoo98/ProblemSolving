#include <stdio.h>
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

#define CUT 1000000000

using namespace std;

/*struct type_name {

}srt;*/

//vector <type> vec;
//stack <type> stk;
//queue <type> q;
//string str;
//map <key_type,value_type> m;
int dp[205][205];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int i, j;//for문변수-->가끔식 long으로
	int n, k;
	cin >> n >> k;
	for (i = 0; i <= n; i++) {
		dp[i][0] = 1;
		dp[i][1] = 1;
	}
	for (int h = 2; h <= k; h++) {
		for (i = 0; i <= n; i++) {
			for (j = 0; j <= i; j++) {
				dp[i][h] = (dp[i][h] % CUT + dp[i - j][h - 1] % CUT) % CUT;
			}
		}
	}
	cout << dp[n][k];
	




	return 0;
}