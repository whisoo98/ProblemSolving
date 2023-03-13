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
int arr[500][500];
int sum[500][500];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int i, j;//for문변수-->가끔식 long으로
	int n;
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		for (j = 0; j <= i; j++) {
			scanf("%d", &arr[i][j]);
		}
	}
	sum[0][0] = arr[0][0];
	for (i = 0; i < n; i++) {
		for (int k = 0; k <= i; k++) {
			if (i == 0) continue;
			if (k == 0) {
				sum[i][k] = sum[i - 1][k] + arr[i][k];
			}
			else if (k == i) {
				sum[i][k] = sum[i - 1][k-1] + arr[i][k];
			}
			else {
				sum[i][k] = max(sum[i - 1][k - 1], sum[i - 1][k]) + arr[i][k];
			}
		}
	}
	sort(sum[n - 1], sum[n - 1] + n,greater<int>());
	printf("%d", sum[n - 1][0]);

	return 0;
}