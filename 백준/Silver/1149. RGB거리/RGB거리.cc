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
int rgb[1005][3];
int sum[1005][3];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int i, j;//for문변수-->가끔식 long으로
	int n;
	scanf("%d", &n);
	int r, g, b;
//	i = 1;
//	scanf("%d %d %d", &rgb[i][0], &rgb[i][1], &rgb[i][2]);//1번째 초기화

	for (i = 1; i <= n; i++) {
		scanf("%d %d %d", &rgb[i][0], &rgb[i][1], &rgb[i][2]);
	}
	sum[1][0] = rgb[1][0];
	sum[1][1] = rgb[1][1];
	sum[1][2] = rgb[1][2];
	for (i = 2; i <= n; i++) {
		sum[i][0] = min(sum[i - 1][1], sum[i - 1][2]) + rgb[i][0];
		sum[i][1] = min(sum[i - 1][0], sum[i - 1][2]) + rgb[i][1];
		sum[i][2] = min(sum[i - 1][1], sum[i - 1][0]) + rgb[i][2];
	}
	printf("%d", min(sum[n][0], min(sum[n][1], sum[n][2])));
	return 0;
}