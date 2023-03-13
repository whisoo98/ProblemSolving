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
int arr[1005][1005];
int sum[1005][1005];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int i, j;//for문변수-->가끔식 long으로
	int n, m;
	scanf("%d %d", &n, &m);
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= m; j++) {
			scanf("%d", &arr[i][j]);
		}
	}
	//sum[1][1] = arr[1][1];
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= m; j++) {
			sum[i][j] = max(sum[i - 1][j], sum[i][j - 1]) + arr[i][j];
		}
	}
	/*for (i = 1; i <= n; i++) {
		for (j = 1; j <= m; j++) {
			printf("%3d ",sum[i][j]);
		}
		printf("\n");
	}*/
	printf("%d", sum[n][m]);
	return 0;
}