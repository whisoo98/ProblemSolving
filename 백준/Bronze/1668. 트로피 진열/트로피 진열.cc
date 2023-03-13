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
int arr[55];
//int dp[55];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int i, j;//for문변수-->가끔식 long으로
	int n;
	cin >> n;
	
	for (i = 0; i < n; i++) cin >> arr[i];
	int idx_max = max_element(arr, arr + n) - arr;
	//int idx_min = min_element(arr, arr + n) - arr;
	int st = arr[0], ed = arr[n - 1];
	int m = 0;
	for (i = 1; i <= idx_max; i++) {
		if (arr[i] > st) {
			m++;
			st = arr[i];
		}
	}
	cout << m + 1 << " ";
	m = 0;
	for (i = n-1; i >= idx_max; i--) {
		if (arr[i] > ed) {
			ed = arr[i];
			m++;
		}
	}
	cout << m + 1;

	return 0;
}