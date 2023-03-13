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
int dp[2][13000];
int weight[3500];
int price[3500];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int i, j;//for문변수-->가끔식 long으로
	int n, w; cin >> n >> w;
	for (i = 0; i < n; i++) {
		int a, b; cin >> a >> b;
		weight[i + 1] = a;
		price[i + 1] = b;
	}
	for (i = 1; i <= n; i++) {
		for (j = 0; j <= w; j++) {
			if (j >= weight[i]) {
				dp[i % 2][j] = max(dp[(i + 1) % 2][j], dp[(i + 1) % 2][j - weight[i]] + price[i]);
			}
			else dp[i % 2][j] = dp[(i + 1) % 2][j];
		}
	}
	int idx = max_element(dp[n % 2], dp[n % 2] + w+1) - dp[n % 2];
	cout << dp[n % 2][idx];
	//for(i=0;i<n;i++) {}
	//for(i=0;i<n;i++) { for(j=0;j<n;j++) { } }

	return 0;
}