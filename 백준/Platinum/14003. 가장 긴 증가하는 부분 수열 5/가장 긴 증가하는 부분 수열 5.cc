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
#define N 1000000

int arr[N + 5];
int dp[N + 5];
int point[N + 5];
stack<int>stk;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int i, j;//for문변수-->가끔식 long으로
	int n; cin >> n;
	for (i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	int m = 1;
	dp[1] = arr[1];
	point[1] = 1;
	for (i = 2; i <= n; i++) {
		int idx = lower_bound(dp + 1, dp + 1 + m, arr[i]) - dp;
		dp[idx] = arr[i];
		point[i] = idx;
		m = max(m, idx);
	}
	cout << m << "\n";
	for (i = n; i > 0 && m > 0; i--) {
		if (point[i] == m) {
			stk.push(arr[i]);
			m--;
		}
	}
	int size = stk.size();
	for (i = 0; i < size; i++) {
		cout << stk.top()<<" ";
		stk.pop();
	}
	//for(i=0;i<n;i++) {}
	//for(i=0;i<n;i++) { for(j=0;j<n;j++) { } }

	return 0;
}