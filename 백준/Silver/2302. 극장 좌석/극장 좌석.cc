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
int dp[50];
int arr[50];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int i, j;//for문변수-->가끔식 long으로
	int n,m; scanf("%d %d", &n,&m);
	
	for (i = 1; i <= m; i++) {
		scanf("%d", &arr[i]);
	}
	arr[i] = n + 1;
	
	dp[0] = 1;
	dp[1] = 1;
	for (i = 2; i <= 40; i++) {
		dp[i] = dp[i - 1] + dp[i - 2];
	}
	int ans = 1;
	for (i = 1; i <= m+1; i++) ans *= dp[arr[i]-arr[i-1]-1];
	printf("%d", ans);
	return 0;
}