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

pair<int, int>p[300];
int dp[260][63000];//i번까지 배분 완료, a기계가 j만큼시간을 사용했을 대 b기계가 사용하는 최소시간
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int i, j;//for문변수-->가끔식 long으로
	int n; cin >> n;
	for (i = 1; i <= n; i++) {
		cin >> p[i].first >> p[i].second;
	}
	int K = 987654321;
	sort(p + 1, p + 1 + n);

	for (j = 1; j <= 62500; j++) dp[0][j] = 62500;

	for (i = 1; i <= n; i++) {
		for (j = 0; j <= 62500; j++) {
			if (j >= p[i].first) {
				dp[i][j] = min(dp[i - 1][j] + p[i].second, dp[i - 1][j - p[i].first]);
			}
			else dp[i][j] = dp[i - 1][j] + p[i].second;
		}
	}
	int k = 62500;
	//cout << dp[n][62500];
	for (i = 1; i <= 62500; i++) {
			k = min(k, max(dp[n][i],i));
		//cout << dp[n][i] << endl;
	}
	cout << k;
	//for(i=0;i<n;i++) {}
	//for(i=0;i<n;i++) { for(j=0;j<n;j++) { } }





	
	return 0;
}