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

//int dp[505][505][505];
int dp[505][505];
pair<int, int> p[1005];
int n;

int mat(int x, int y) {
	if (dp[x][y] != INT_MAX) return dp[x][y];
	if (x >= y) return dp[x][y] = 0;
	if (x + 1 == y) return dp[x][y]=p[x].first * p[x].second * p[y].second;
	for (int i = x; i <= y; i++) {
		dp[x][y] = min(dp[x][y], mat(x, i) + mat(i + 1, y) + p[x].first*p[i].second*p[y].second);
	}
	return dp[x][y];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int i, j;//for문변수-->가끔식 long으로
	cin >> n;
	for (i = 1; i <= 500; i++) {
		for (j = 1; j <= 500; j++) dp[i][j] = INT_MAX;
	}
	for (i = 1; i <= n; i++) {
		cin >> p[i].first >> p[i].second;
	}
	/*for (i = 1; i < n; i++) {
		dp[i][i + 1] = p[i].first*p[i].second*p[i + 1].second;
		cout << dp[i][i + 1] << endl;
	}*/
	
	mat(1, n);
	cout << dp[1][n];
	//for(i=0;i<n;i++) {}
	//for(i=0;i<n;i++) { for(j=0;j<n;j++) { } }

	return 0;
}