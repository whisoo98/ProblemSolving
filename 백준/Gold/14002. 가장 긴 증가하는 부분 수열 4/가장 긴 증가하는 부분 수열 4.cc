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
int arr[1005];
int dp[1005];
stack<int> stk;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int i, j;//for문변수-->가끔식 long으로
	int n; cin >> n;
	int m = -1;
	for (i = 1; i <= n; i++) cin >> arr[i];
	for (i = 1; i <= n; i++) {
		for (j = 0; j <= i; j++) {
			if (arr[i] > arr[j]) {
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
		m = max(m, dp[i]);
	}
	int temp = m - 1;
	int idx = find(dp + 1, dp + 1 + n, m) - dp;
	stk.push(arr[idx]);
	for (i = idx - 1; i > 0; i--) {
		if (dp[i] == temp && arr[i] < arr[idx]) {
			stk.push(arr[i]);
			idx = i;
			temp--;
		}
	}
	int size = stk.size();
	cout << m << "\n";

	for (i = 0; i < size; i++) {
		cout << stk.top()<<" ";
		stk.pop();
	}
	//for(i=0;i<n;i++) {}
	//for(i=0;i<n;i++) { for(j=0;j<n;j++) { } }

	return 0;
}