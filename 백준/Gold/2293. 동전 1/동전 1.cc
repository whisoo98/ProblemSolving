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
int coin[105];
int dp[10005];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int i, j;//for문변수-->가끔식 long으로
	int n, k; cin >> n >> k;
	for (i = 1; i <= n; i++) cin >> coin[i];
	sort(coin + 1, coin + 1 + n);
	dp[0] = 1; // -> 안 넣는 경우도 하나의 경우이다.

	for (i = 1; i <= n; i++) {
		for (j = coin[i]; j <= k; j++) {
			dp[j] += dp[j - coin[i]];
		}
	}
	cout << dp[k];
	//for(i=0;i<n;i++) {}
	//for(i=0;i<n;i++) { for(j=0;j<n;j++) { } }

	return 0;
}