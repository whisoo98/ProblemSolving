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
int n;
int arr[100005];
int M;
long long parametric(int low, int high) {
	while (low <= high) {
		int mid = (low + high) / 2;
		int sum = 0;
		for (int i = 1; i <= n; i++) {
			if (mid > arr[i]) {
				sum += arr[i];
			}
			else {
				sum += mid;
			}
		}
		if (sum > M) {
			high = mid - 1;
		}
		else if (sum < M) {
			low = mid + 1;
		}
		else {
			return mid;
		}
	}
	return high;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int i, j;//for문변수-->가끔식 long으로
	cin >> n;
	int sum = 0;
	for (i = 1; i <= n; i++) {
		cin >> arr[i];
		sum += arr[i];
	}
	cin >> M;
	sort(arr + 1, arr + 1 + n, greater<int>());
	if (M >= sum) {
		cout << arr[1];
		return 0;
	}
	cout<<parametric(0, arr[1]);

	return 0;
}