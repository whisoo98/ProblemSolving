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

long long dp[100005];

long long ott(int x) {
	if (dp[x] != -1)return dp[x];
	return dp[x] = (ott(x - 2) + ott(x - 4) + ott(x - 6)+ 1000000009)% 1000000009;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int i, j;//for문변수-->가끔식 long으로
	for (i = 0; i <= 100000; i++) dp[i] = -1;
	dp[0] = 1;
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 2;
	dp[4] = 3;
	dp[5] = 3;
	dp[6] = 6;
	for (i = 7; i <= 100000; i++) ott(i);
	//for (i = 0; i <= 100000; i++) cout << dp[i] << endl;
	int T; cin >> T;
	while (T--) {
		int n; cin >> n;
		cout << dp[n] << "\n";
	}

	//for(i=0;i<n;i++) {}
	//for(i=0;i<n;i++) { for(j=0;j<n;j++) { } }

	return 0;
}