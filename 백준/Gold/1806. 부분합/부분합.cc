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
int arr[100005];
int dp[100005];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int i, j;//for문변수-->가끔식 long으로
	int m, n, s; scanf("%d %d", &n, &s);
	for (i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
		//dp[i] = dp[i - 1] + arr[i];
	}

	int  st = 0, ed = 0, sum = 0, ans = 200000;
	while (1) {
		if (sum >= s) {
			ans = min(ans, ed - st);
			sum -= arr[st++];
		}
		else if (ed == n) break;
		else {
			sum += arr[ed++];
		}
	}
	if (ans == 200000) printf("0");
	else printf("%d", ans);


	return 0;
}