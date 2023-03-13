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
int dp[25][105];
int weight[25];
int price[25];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int i, j;//for문변수-->가끔식 long으로
	int n; cin >> n;
	for (j = 1; j <= n; j++) {
		cin >> weight[j];
	}
	for (i = 1; i <= n; i++) {
		cin >> price[i];
	}
	for (i = 1; i <= n; i++) {
		for (j = 0; j < 100; j++) {
			if (j >= weight[i]) {
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weight[i]] + price[i]);
			}
			else dp[i][j] = dp[i - 1][j];
		}
	}
	sort(dp[n], dp[n] + 101, greater<int>());
	cout << dp[n][0];

	//for(i=0;i<n;i++) {}
	//for(i=0;i<n;i++) { for(j=0;j<n;j++) { } }

	return 0;
}