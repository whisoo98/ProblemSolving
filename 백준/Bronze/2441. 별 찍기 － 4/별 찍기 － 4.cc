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
char arr[105][105];
int main()
{
	//ios_base::sync_with_stdio(false);
	//cin.tie(NULL);
	//cout.tie(NULL);
	int i, j;//for문변수-->가끔식 long으로
	int T;
	scanf("%d", &T);
	for (i = 1; i <= T; i++) {
		for (j = i; j <= T; j++) {
			arr[i][j] = '*';
		}
	}
	for (i = 1; i <= T; i++) {
		for (j = 1; j <= T; j++) {
			if (arr[i][j] == '\0') printf(" ");
			else printf("%c", arr[i][j]);
		}
		printf("\n");
	}
	return 0;
}