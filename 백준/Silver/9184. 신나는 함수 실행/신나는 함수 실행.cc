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
int dp[25][25][25];

int w(int a, int b, int c) {
	
	if (a <= 0 || b <= 0 || c <= 0) return 1;
	if (a > 20 || b > 20 || c > 20) return dp[20][20][20] = w(20, 20, 20);
	if (dp[a][b][c] != -INT_MAX) return dp[a][b][c];
	

	if (a < b && b < c) return  dp[a][b][c] = w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c);
	else return  dp[a][b][c] = w(a - 1, b, c) + w(a - 1, b - 1, c) + w(a - 1, b, c - 1) - w(a - 1, b - 1, c - 1);
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int i, j;//for문변수-->가끔식 long으로
	//int n; scanf("%d", &n);
	for (i = 0; i <= 20; i++) {
		for (j = 0; j <= 20; j++) {
			for (int k = 0; k <= 20; k++) dp[i][j][k] = -INT_MAX;
		}
	}
	w(20, 20, 20);
	while (1) {
		int a, b, c; scanf("%d %d %d", &a, &b, &c);
		if (a == -1 && b == -1 && c == -1)return 0;
		printf("w(%d, %d, %d) = %d\n", a, b, c, w(a, b, c));
	}

	//for(i=0;i<n;i++) {}
	//for(i=0;i<n;i++) { for(j=0;j<n;j++) { } }

	return 0;
}