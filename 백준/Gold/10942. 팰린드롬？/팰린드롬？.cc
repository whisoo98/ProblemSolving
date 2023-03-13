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
int dp[2005][2005];
int arr[2005];
int n;

/*int palin(int start, int end) {
	if (start > end) return 0;
	if (dp[start][end]==-1) {
		dp[start][end] = 0;
		if (end - start == 1) {
			if (arr[start] == arr[end]) return dp[start][end] = 1;
			else return dp[start][end] = 0;
		}//ok
		else {
			if (arr[start] == arr[end]) dp[start][end] = palin(start + 1, end - 1);
			else dp[start][end] = 0;
		}

		for (int k = start + 1; k < end; k++) {
			dp[start][end] = max((palin(start, k)+palin(k, end))/2, dp[start][end]);
		}
		return dp[start][end];
	}
	else return dp[start][end];
}*/
int palin(int start, int end) {
	if (start > end) return 0;
	if (dp[start][end] == -1) {
		dp[start][end] = 0;
		if (end - start == 1) {
			if (arr[start] == arr[end]) return dp[start][end] = 1;
			else return dp[start][end] = 0;
		}
		else {
			if (arr[start] == arr[end]) return dp[start][end] = palin(start + 1, end - 1);
			else return dp[start][end] = 0;
		}
	}
	else return dp[start][end];
}
int main()
{
	///ios_base::sync_with_stdio(false);
	//cin.tie(NULL);
	//cout.tie(NULL);
	int i, j;//for문변수-->가끔식 long으로
	scanf("%d", &n);
	for (i = 1; i <= n; i++) {
		scanf("%d", &arr[i]);
		//dp[i][i] = 1;
	}


/*for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++) {
			for (int k = i; k < j; k++) {
				if (dp[i][k] * dp[k+1][j]) dp[i][j] = 1;
			}
		}
	}*/
	for (i = 1; i <= n; i++) {
		for (j = i; j <= n; j++) {
			if (i == j) dp[i][j] = 1;
			else dp[i][j] = -1;
		}
	}
	//palin(1, n);


	int m; scanf("%d", &m);
	for (i = 1; i <= m; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		printf("%d\n", palin(a,b));
		//printf("%d\n", palin(a, b));
	}

	return 0;
}