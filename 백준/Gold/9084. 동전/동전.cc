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


using namespace std;

/*struct type_name {

}srt;*/

//vector <type> vec;
//stack <type> stk;
//queue <type> q;
//string str;
//map <key_type,value_type> m;
int coin[25];
int dp[10005] = { 1, };
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int i, j;//for문변수-->가끔식 long으로
	int T;
	scanf("%d", &T);
	while (T--) {
		int n;
		scanf("%d", &n);
		for (i = 1; i <= 24; i++) {
			coin[i] = 0;
		}
		for (j = 1; j <= 10000; j++) {
			dp[j] = 0;
		}

		for (i = 1; i <= n; i++) scanf("%d", &coin[i]);
		int target; scanf("%d", &target);

		for (i = 1; i <= n; i++) {
			for (j = coin[i]; j <= target; j++) {
				dp[j] += dp[j - coin[i]];
			}
		}
		printf("%d\n", dp[target]);

	}

	return 0;
}