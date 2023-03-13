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

vector <int> vec;
//stack <type> stk;
//queue <type> q;
//string str;
//map <key_type,value_type> m;

int dp[505][505];
int sum[505][505];
int hap(int i, int j) {
	if (i == j) return 0;
	if (dp[i][j] == 987654321) {
		for (int k = i; k < j; k++) {
			dp[i][j] = min(dp[i][j], hap(i, k) + hap(k + 1, j)+sum[i][j]);
		}
		return dp[i][j];
	}
	else return dp[i][j];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int i, j;//for문변수-->가끔식 long으로
	int T;
	scanf("%d", &T);
	while (T--) {
		for (i = 0; i < 505; i++) {
			for (j = 0; j < 505; j++) {
				dp[i][j] = 987654321;
			}
		}
		int n;
		scanf("%d", &n);
		
		for (i = 0; i < n; i++) {
			int temp;
			scanf("%d", &temp);
			vec.push_back(temp);
		}
		for (i = 0; i < n; i++) {
			for (j = i; j < n; j++) {
				if (i == j) sum[i][j] = vec[i];
				sum[i][j] = sum[i][j - 1] + vec[j];
			}
		
		}
		hap(0, n - 1);

		printf("%d\n", dp[0][n - 1]);
		vec.clear();

	}

	return 0;
}