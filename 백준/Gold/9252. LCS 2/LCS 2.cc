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
stack <char> stk;
//queue <type> q;
//string str;
//map <key_type,value_type> m;
char str1[1005];
char str2[1005];
int dp[1005][1005];
int arr[1005][1005];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int i, j;//for문변수-->가끔식 long으로
	scanf("%s", str1);
	scanf("%s", str2);
	int len1 = strlen(str1);
	int len2 = strlen(str2);
	for (i = 0; i < len1; i++) {
		for (j = 0; j < len2; j++) {
			if (str1[i] == str2[j]) {
				dp[i + 1][j + 1] = dp[i][j] + 1;
				arr[i + 1][j + 1] = 1;
			}
			else {
				if (dp[i][j + 1] < dp[i + 1][j]) {
					dp[i + 1][j + 1] = dp[i + 1][j];
					arr[i + 1][j + 1] = 3;
				}
				else {
					dp[i + 1][j + 1] = dp[i][j + 1];
					arr[i + 1][j + 1] = 2;
				}

			}
		}
	}
	printf("%d\n", dp[len1][len2]);
	i = len1, j = len2;
	while (i > 0 && j > 0) {
		if (arr[i][j] == 1) {
			stk.push(str1[i-1]);
			i--;
			j--;
		}
		else if (arr[i][j] == 3) {
			j--;
		}
		else if (arr[i][j]==2){
			i--;
		}
	}
	while (!stk.empty()) {
		printf("%c", stk.top());
		stk.pop();
	}
	return 0;
}