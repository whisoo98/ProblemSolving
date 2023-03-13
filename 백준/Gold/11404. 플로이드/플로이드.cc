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
int village[105][105];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int i, j;//for문변수-->가끔식 long으로
	int n, m;
	scanf("%d %d", &n, &m);
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++) {
			village[i][j] = 200000000;
		}
	}
	for (i = 0; i < m; i++) {
		int st, ed,temp;
		scanf("%d %d", &st, &ed);
		scanf("%d", &temp);
		village[st][ed] = min(temp, village[st][ed]);
	}
	for (int k = 1; k <= n; k++) {
		for (i = 1; i <= n; i++) {
			for (j = 1; j <= n; j++) {
				if (i == j) {
					village[i][j] = 0;
					continue;
				}
				village[i][j] = min(village[i][j], village[i][k] + village[k][j]);
			}
		}
	}
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++) {
			if (village[i][j] == 200000000) printf("0 ");
			else printf("%d ", village[i][j]);
		}
		printf("\n");
	}
	return 0;
}