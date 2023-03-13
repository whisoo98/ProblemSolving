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
double arr[10005];
double dp[10005];
double dp2[10005];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int i, j;//for문변수-->가끔식 long으로
	int n; scanf("%d", &n);
	int flag = 0;
	for (i = 1; i <= n; i++) {
		scanf("%lf", &arr[i]);
		if (arr[i] > 1) flag = 1;
	}
	dp[1] = dp2[1] = arr[1];
	dp2[1] = max(dp2[1], 1.0);
	if (flag) {
		for (i = 2; i <= n + 1; i++) {
			dp2[i] = max(dp2[i - 1] * arr[i], 1.0);
			dp[i] = max(dp[i - 1], dp2[i]);
		}
		printf("%.3lf",dp[n + 1]);
	}
	else {
		int idx = max_element(arr + 1, arr + 1 + n) - arr;
		//cout << arr[idx];
		printf("%.3lf", arr[idx]);
	}
	//for()
	//for(i=0;i<n;i++) {}
	//for(i=0;i<n;i++) { for(j=0;j<n;j++) { } }

	return 0;
}