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
#define N 305
#define endl "\n"

using namespace std;

/*struct type_name {

}srt;*/

//vector <type> vec;
//stack <type> stk;
//queue <type> q;
//string str;
//map <key_type,value_type> m;
int n, m;
int arr[N];

void Solution(int mini, int maxi) {
	int mid;
	while (mini <= maxi) {
		mid = (mini + maxi) / 2;
		int cnt = 1;
		int sum = 0;
		for (int i = 0; i < n; i++) {
			sum += arr[i];
			if (sum > mid) {
				cnt++;
				sum = arr[i]; //???????????
			}
		}
		if (cnt <= m) maxi = mid - 1;
		else mini = mid + 1;
	}
	cout << mini << endl;
	int sum = 0;
	int cnt = 0;
	int left, right;
	for (int i = 0, j = 0; i < n; i++) {
		sum += arr[i];
		if (sum > mini) {
			sum = arr[i];
			m--;
			cout << cnt << " ";
			cnt = 0;
		}
		cnt++;
		if (n - i == m)break;
	}
	cout << cnt << " ";
	m--;
	while (m--) {
		cout << 1 << " ";
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int i, j;//for문변수-->가끔식 long으로
	cin >> n >> m;
	int mini = -1;
	int maxi = 0;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		mini = max(mini, arr[i]);
		maxi += arr[i];
	}
	Solution(mini, maxi);
	

	return 0;
}