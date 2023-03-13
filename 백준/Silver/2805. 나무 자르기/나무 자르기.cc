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
int n, m;
int arr[1000005];
long long parametric(long long low, long long high) {
	while (low <= high) {
		long long mid = (low + high) / 2;
		long long sum = 0;
		for (int i = 0; i < n; i++) {
			if (arr[i] > mid) {
				sum += arr[i] - mid;
			}
		}
		if (sum < m) {
			high = mid - 1;
		}
		else if (sum > m) {
			low = mid + 1;
		}
		else return mid;
	}
	return high;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int i, j;//for문변수-->가끔식 long으로
	cin >> n >> m;
	long long sum = 0;
	for (i = 0; i < n; i++) cin >> arr[i];
	sort(arr, arr + n, greater<int>());
	cout<<parametric(0, arr[0]);
	return 0;
}