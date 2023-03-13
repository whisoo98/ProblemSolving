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
int arr[1500];
int dp[1500];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int i, j;//for문변수-->가끔식 long으로
	int n; scanf("%d", &n);

	for (i = 1; i <= n; i++) {
		scanf("%d", &arr[i]);
	}
	dp[0] = 0;
	dp[1] = 1;
	for (i = 1; i <= n; i++) {
		if (!dp[i]) continue;
		for (j = 1; j <= arr[i]; j++) {
			if (dp[i + j]) continue;
			dp[i + j] = dp[i] + 1;
		}
	}
	//for (i = 1; i <= n; i++) cout << dp[i] << " ";
	//cout << dp[n + 1];
	if (!dp[n]) printf("-1");
	else printf("%d", dp[n]-1);
	return 0;
}