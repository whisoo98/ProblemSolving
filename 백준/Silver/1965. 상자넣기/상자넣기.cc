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
int arr[1005];
int dp[1005];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int i, j;//for문변수-->가끔식 long으로
	int n;
	scanf("%d", &n);
	for (i = 1; i <= n; i++) scanf("%d", &arr[i]);
	dp[1] = 1;
	for (i = 2; i <= n; i++) {
		for (j = 1; j < i; j++) {
			if (arr[i] > arr[j]) dp[i] = max(dp[i], dp[j]);
		}
		dp[i]++;
	}
	sort(dp, dp + 1004,greater<int>());
	printf("%d", dp[0]);
	return 0;
}