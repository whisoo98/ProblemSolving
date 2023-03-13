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
/*char arr1[16];
char arr2[16];
char arr3[16];
char arr4[16];
char arr5[16];*/
char arr[5][16];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	char empty = '\0';
	int i, j;//for문변수-->가끔식 long으로
	for (i = 0; i < 5; i++) scanf("%s", arr[i]);
	for (i = 0; i < 16; i++) {
		for (j = 0; j < 5; j++) {
			if (arr[j][i] == empty) continue;
			printf("%c", arr[j][i]);
		}
	}

	return 0;
}