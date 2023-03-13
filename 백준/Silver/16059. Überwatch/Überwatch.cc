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
int arr[300005];
int dp[2][300005];
int M[300005];
vector<pair<int, int>> v;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int i, j;//for문변수-->가끔식 long으로
	int n, m; cin >> n >> m;
	for (i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	for (i = m + 1; i <= n; i++) {
		dp[0][i] = max(dp[1][i - 1], dp[0][i - 1]);
		dp[1][i] = max(dp[0][i - m], dp[1][i - m]) + arr[i];
		M[i] = max(dp[0][i], dp[1][i]);
	}
	sort(M + 1, M + 1 + n, greater<int>());
	cout << M[1];
	//for(i=0;i<n;i++) {}
	//for(i=0;i<n;i++) { for(j=0;j<n;j++) { } }

	return 0;
}