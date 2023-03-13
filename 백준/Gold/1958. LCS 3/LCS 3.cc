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
char str1[105];
char str2[105];
char str3[105];
int dp[105][105][105];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int i, j;//for문변수-->가끔식 long으로
	scanf("%s %s %s", str1, str2, str3);
	int len1 = strlen(str1);
	int len2 = strlen(str2);
	int len3 = strlen(str3);
	for (i = 0; i < len1; i++) {
		for (j = 0; j < len2; j++) {
			for (int k = 0; k < len3; k++) {
				if (str1[i] == str2[j] && str1[i] == str3[k]) {
					dp[i + 1][j + 1][k + 1] = dp[i][j][k] + 1;
				}
				else dp[i + 1][j + 1][k + 1] = max(dp[i][j + 1][k + 1], max(dp[i + 1][j][k + 1], dp[i + 1][j + 1][k]));
			}
		}
	}
	//cout << "!";
	printf("%d", dp[len1][len2][len3]);
	return 0;
}