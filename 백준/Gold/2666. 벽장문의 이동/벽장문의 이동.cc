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
int arr[24];
int dp[25][25][25];
int m;
int closet(int left, int right, int depart,int cnt) {
	if (cnt >= m) return 0;
	//if (dp[left][right][depart] != -1) return dp[left][right][depart];
	return dp[left][right][depart] = min(closet(depart, right, arr[cnt + 1], cnt + 1) + abs(depart - left), closet(left, depart, arr[cnt + 1], cnt + 1) + abs(depart - right));
	/*if (abs(depart - left) == abs(depart - right)) {
		return dp[left][right][depart] = min(closet(depart, right, arr[cnt + 1], cnt + 1) + abs(depart - left), closet(left, depart, arr[cnt + 1], cnt + 1) + abs(depart - right));
	}
	else if (abs(depart - left) < abs(depart - right)) {
		return dp[left][right][depart] = closet(depart, right, arr[cnt + 1], cnt + 1)+ abs(depart - left);
	}
	else {
		return dp[left][right][depart] = closet(left, depart, arr[cnt + 1], cnt + 1)+ abs(depart - right);
	}*/

}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int i, j;//for문변수-->가끔식 long으로
	int n; cin >> n;
	int a, b; cin >> a >> b;
	int st = min(a, b), ed = max(a, b);
	cin >> m;
	for (i = 0; i <= 20; i++) {
		for (j = 0; j <= 20; j++) {
			for (int k = 0; k <= 20; k++) dp[i][j][k] = -1;
		}
	}
	dp[st][ed][0] = 0;
	for (i = 0; i < m; i++) {
		cin >> arr[i];
	}
	dp[st][ed][0] = closet(st, ed, arr[0], 0);
	cout << dp[st][ed][0];
	return 0;
}