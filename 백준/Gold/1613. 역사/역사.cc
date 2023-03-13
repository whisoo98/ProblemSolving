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
int dp[405][405];
vector<int>edge[405];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int i, j;//for문변수-->가끔식 long으로
	int n, k; scanf("%d %d", &n, &k);
	for (i = 0; i < k; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		//edge[a].push_back(b);
		dp[a][b] = 1;
		dp[b][a] = -1;
	}

	for (int k = 1; k <= n; k++) {
		for (i = 1; i <= n; i++) {
			for (j = 1; j <= n; j++) {
				if (dp[i][k] == 1 && dp[k][j] == 1) { dp[i][j] = 1; }
				else if (dp[i][k] == -1 && dp[k][j] == -1) { dp[i][j] = -1; }
			}
		}
	}


	int s; scanf("%d", &s);
	for (i = 0; i < s; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		if (dp[a][b] == 0) {
			printf("0\n");
			continue;
		}
		else if (dp[a][b] > 0) {
			printf("-1\n");
			continue;
		}
		else {
			printf("1\n");
			continue;
		}
		
	}



	return 0;
}