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
int arr[25];
int n, target;
int cnt;
int sum[25];
void dfs(int level) {

	if (level  == n) {
		if (sum[n] == target) cnt++;
		return;
	}

	sum[level + 1] = sum[level] + arr[level];
	dfs(level + 1);
	sum[level + 1] -= arr[level];
	dfs(level + 1);
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int i, j;//for문변수-->가끔식 long으로
	cin >> n >> target;
	for (i = 0; i < n; i++) cin >> arr[i];
	dfs(0);
	if (!target) cout << cnt - 1;
	else cout << cnt;
	return 0;
}