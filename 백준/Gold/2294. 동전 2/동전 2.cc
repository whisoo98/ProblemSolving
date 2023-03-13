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
//int coin[105];
vector<int> coin;
int coin2[100005];
int dp[10005];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int i, j;//for문변수-->가끔식 long으로
	int n, k; cin >> n >> k;
	for (i = 0; i <= k; i++) {
		dp[i] = 987654321;
	}
	for (i = 1; i <= n; i++) {
		int a; cin >> a;
		if (!coin2[a]) {
			coin2[a] = 1;
			coin.push_back(a);
			dp[a] = 1;
		}
	}
	sort(coin.begin(), coin.end());

	int size = coin.size();
	dp[0] = 1;
	for (i = 0; i < size; i++) {
		for (j = coin[i]; j <= k; j++) {
			if (dp[j - coin[i]]!=987654321) {
				dp[j] = min(dp[j], dp[j - coin[i]] + 1);
			}
		}
	}
	if (dp[k] == 987654321)cout << "-1\n";
	else cout << dp[k];
	//for(i=0;i<n;i++) {}
	//for(i=0;i<n;i++) { for(j=0;j<n;j++) { } }

	return 0;
}