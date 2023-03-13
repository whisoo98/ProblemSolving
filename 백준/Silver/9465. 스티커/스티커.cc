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
int sticker[3][100005];
int sum[3][100005];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int i, j;//for문변수-->가끔식 long으로
	int t;
	scanf("%d", &t);
	while (t--) {
		int n;
		//int sum = 0;
		scanf("%d", &n);
		for (i = 1; i <= 2; i++) {
			for (j = 1; j <= n; j++) {
				scanf("%d", &sticker[i][j]);
				sum[i][j] = sticker[i][j];
			}
		}
		
			for (j = 2; j <= n; j++) {
				sum[1][j] += max(sum[2][j - 1], sum[2][j - 2]);
				sum[2][j] += max(sum[1][j - 1], sum[1][j - 2]);
			}
			printf("%d\n", max(sum[1][n], sum[2][n]));

		}
			

	return 0;
}