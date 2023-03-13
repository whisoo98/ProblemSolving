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
#include<climits>

using namespace std;

/*struct type_name {

}srt;*/

//vector <type> vec;
//stack <type> stk;
//queue <type> q;
//string str;
//map <key_type,value_type> m;

long long arr[1000005];
long long k, n;
vector<long long>v;
int parSearch(long long left, long long right) {
	while (left <= right) {
		//cout << "!";
		long long mid = (left + right) / 2;
		long long cnt = 0;
		for (int i = 0; i < k; i++) {
			cnt += arr[i + 1] / mid;
		}
		if (cnt >= n) {
			left = mid + 1;
		}
		else if (cnt < n) {
			right = mid - 1;
		}
		/*else {
			v.push_back(mid);
			left = mid+1;
		}*/
	}
	return right;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int i, j;//for문변수-->가끔식 long으로
	cin >> k >> n;
	for (i = 0; i < k; i++) cin >> arr[i + 1];
	cout<<parSearch(1, INT_MAX);
	//sort(v.begin(), v.end(), greater<long long>());
	//cout << v[0];
	
	//cout<<parSearch(0, INT_MAX);
	return 0;
}