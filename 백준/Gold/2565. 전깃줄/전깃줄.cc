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
vector<pair<int, int>> v;
int arr[505];
int dp[505];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int i, j;//for문변수-->가끔식 long으로
	int n; scanf("%d", &n);
	int num_max = -1;
	for (i = 0; i < n; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		arr[b] = a;
		dp[b] = 1;
		num_max = max(num_max, b);
		//v.push_back({ b,a });
	}

	for (i = 1; i <= num_max; i++) {
		for (j = 1; j <= i; j++) {
			if (arr[i] > arr[j]) dp[i] = max(dp[i], dp[j] + 1);
		}

	}
	sort(dp + 1, dp + 1 + num_max, greater<int>());
	printf("%d", n - dp[1]);
	return 0;
}