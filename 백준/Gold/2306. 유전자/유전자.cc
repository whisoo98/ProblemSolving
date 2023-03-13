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
#include<cstring>

using namespace std;

/*struct type_name {

}srt;*/

//vector <type> vec;
//stack <type> stk;
//queue <type> q;
//string str;
//map <key_type,value_type> m;
char dna[505];
char atgc[5] = "atgc";
int dp[505][505];

int koi(int i, int j) {
	if (i >= j) return 0;
	if (dp[i][j] == -1) {
		dp[i][j] = 0;
		 
		for (int k = i; k < j; k++) {
			dp[i][j] = max(koi(i, k) + koi(k + 1, j), dp[i][j]);
		}
		if (((dna[i] == 'a') && (dna[j] == 't')) || ((dna[i] == 'g') && (dna[j] == 'c'))) {
			dp[i][j] = max(koi(i + 1, j - 1) + 2, dp[i][j]);
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
	scanf("%s", dna);
	//i = 0; j = strlen(dna);
	int len = strlen(dna);
	for (i = 0; i <= len; i++) {
		for (j = 0; j <= len; j++) {
			dp[i][j] = -1;
		}
	}
	koi(0, len);
	printf("%d", dp[0][len]);
	return 0;
}