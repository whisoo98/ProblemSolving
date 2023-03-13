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
int arr[305][305];
//int sum[10005];
int sum;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int i, j;//for문변수-->가끔식 long으로
	int n, m;
	//cin >> n >> m;
	scanf("%d %d", &n, &m);
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= m; j++) {
			//scanf("%d", &arr[i][j]);
			scanf("%d", &arr[i][j]);
		}
	}
	int k;
	scanf("%d", &k);
	int temp = k;
	while (temp) {
		sum = 0;
		int x1, x2, y1, y2;
		scanf("%d %d %d %d", &y1, &x1, &y2, &x2);
		for (i = y1; i <= y2; i++) {
			for (j = x1; j <= x2; j++) {
				sum += arr[i][j];
			}
		}
		printf("%d\n", sum);
		temp--;
	}
	//for (i = k; i > 0; i--) printf("%d\n", sum[i]);
	return 0;
}