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


using namespace std;

/*struct type_name {

}srt;*/

//vector <type> vec;
//stack <type> stk;
//queue <type> q;
//string str;
//map <key_type,value_type> m;

long long dp[70][15];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int i, j;//for문변수-->가끔식 long으로
	int T; scanf("%d", &T);
	dp[0][0] = 0;
	//dp[1] = 10;//0~9
	for (i = 0; i <= 9; i++) dp[1][i] = 1; dp[1][10] = 10;
	for (i = 0; i <= 9; i++) dp[2][i] = 10-i; dp[2][10] = 55;

	for (i = 3; i <= 64; i++) {

		for (j = 0; j <= 9; j++) {
			if (j == 0) dp[i][10] += dp[i][j] = dp[i - 1][10];
			else if (j < 10)dp[i][10] += dp[i][j] = dp[i][j - 1] - dp[i - 1][j - 1];
			
		}
	}
	

	while (T--) {
		int n; scanf("%d", &n);
		printf("%lld\n", dp[n][10]);
	}

	//for(i=0;i<n;i++) {}
	//for(i=0;i<n;i++) { for(j=0;j<n;j++) { } }

	return 0;
}