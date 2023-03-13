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
int weight[105];
int value[105];
int dp[105][100005];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int i, j;//for문변수-->가끔식 long으로
	int n, m; cin >> n >> m;
	for (i = 1; i <= n; i++) {
		cin >> weight[i] >> value[i];
	}
	for (i = 1; i <= n; i++) {
		for (j = 0; j <= m; j++) {
			if (j >= weight[i]) {
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weight[i]] + value[i]);
			}
			else dp[i][j] = dp[i - 1][j];
		}
	}
	cout << dp[n][m];
	//for(i=0;i<n;i++) {}
	//for(i=0;i<n;i++) { for(j=0;j<n;j++) { } }

	return 0;
}