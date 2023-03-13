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
int arr[10005];
int drink[10005][4];//0은 이번잔 안마심 1은 1번째 이전잔을 안마심, 2는 2번째 이전잔을 안마심 3은 이중 최댓값
//ex) drink[1][1]은 1번째잔은 마시고 1번째 이전잔 0번째잔(없음) 은 안마심
int main()
{
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//	cout.tie(NULL);
	int i, j;//for문변수-->가끔식 long으로
	int n;
	scanf("%d", &n);
	for (i = 1; i <= n; i++) scanf("%d", &arr[i]);
	

	if (n == 1) {
		printf("%d", arr[1]);
		return 0;
	}
	if (n == 2) {
		printf("%d", arr[1] + arr[2]);
		return 0;
	}
	if (n == 3) {
		printf("%d", max(arr[1] + arr[2], max(arr[2] + arr[3], arr[1] + arr[3])));
		return 0;
	}
	drink[1][1] = arr[1];
	drink[1][2] = arr[1];
	drink[1][0] = 0;
	drink[1][3] = arr[1];
	drink[2][1] = arr[2];
	drink[2][2] = arr[1] + arr[2];
	drink[2][0] = arr[1];
	drink[2][3] = drink[2][2];
	drink[3][1] = drink[2][0] + arr[3];//arr[1] + arr[3];
	drink[3][2] = drink[2][1] + arr[3];//arr[2] + arr[3];
	drink[3][0] = drink[2][2];//arr[1] + arr[2]
	drink[3][3] = max(max(drink[3][1], drink[3][2]), drink[3][0]);

	for (i = 4; i <= n; i++) {
		drink[i][0] = max(drink[i - 1][3], drink[i - 2][3]);
		drink[i][1] = arr[i] + drink[i - 1][0];
		drink[i][2] = arr[i] + drink[i - 1][1];
		drink[i][3] = max(max(drink[i][1], drink[i][2]), drink[i][0]);
	}
	printf("%d", drink[n][3]);
	return 0;
}