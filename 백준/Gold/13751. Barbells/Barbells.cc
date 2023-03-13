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
int bar[20];
int plate[20];
int n, m;
int ans[50000];
vector<int> arr;
int cnt;
void cal(int left, int right,int level) {
	/*if (level == m){
		if (left == right) {
			int temp = left * 2;
			for (int i = 1; i <= n; i++) {
				arr[cnt] = bar[i] + temp;
				cnt++;
			}
		}
		return;
	}*/
	if (level > m) return;
	if (left == right && left != 0) {
		if (find(arr.begin(), arr.end(), left) != arr.end()) {
			return;
		}
		else {
			arr.push_back(left);
			cal(left + plate[level + 1], right, level + 1);
			cal(left, right, level + 1);
			cal(left, right + plate[level + 1], level + 1);
		}
	}
	else {
		cal(left + plate[level + 1], right, level + 1);
		cal(left, right, level + 1);
		cal(left, right + plate[level + 1], level + 1);
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int i, j;//for문변수-->가끔식 long으로
	 cin >> n >> m;
	for (i = 1; i <= n; i++) cin >> bar[i];
	for (i = 1; i <= m; i++) cin >> plate[i];
	cal(0, 0, 0);
	arr.push_back(0);
	sort(arr.begin(), arr.end());
	sort(bar + 1, bar + 1 + n);
	int cnk = 0;
	for (i = 1; i <= n; i++) {
		for (auto it = arr.begin(); it != arr.end(); it++) {
			ans[cnk] = bar[i] + (*it) * 2;
			cnk++;
		}
	}
	sort(ans, ans + cnk);
	int temp = ans[0];
	for (i = 1; i <= cnk; i++) {
		if (temp != ans[i]) {
			cout << temp << "\n";
			temp = ans[i];
		}
	}
	//for(i=0;i<n;i++) {} 
	//for(i=0;i<n;i++) { for(j=0;j<n;j++) { } }

	return 0;
}