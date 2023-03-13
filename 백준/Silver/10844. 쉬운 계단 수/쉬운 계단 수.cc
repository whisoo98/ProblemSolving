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
#define A 1000000000

using namespace std;

/*struct type_name {

}srt;*/

//vector <type> vec;
//stack <type> stk;
//queue <type> q;
//string str;
//map <key_type,value_type> m;
long long arr[105][10]; // 첫 인덱싱 n길이 두번째 인덱싱 시작하는 숫자
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int i, j;//for문변수-->가끔식 long으로
	int n;
	for (i = 0; i < 10; i++) {
		arr[1][i] = 1;
		arr[2][i] = 2;
	}
	arr[1][0] = 0;
	arr[2][0] = 1;
	arr[2][9] = 1;

	scanf("%d", &n);

	for (i = 3; i <= n; i++) {
		for (j = 0; j < 10; j++) {
			if (j == 0) arr[i][j] = arr[i - 1][1]%A;
			else if (j == 9) arr[i][j] = arr[i - 1][8]%A;
			else arr[i][j] = (arr[i - 1][j - 1]%A + arr[i - 1][j + 1]%A)%A;
		}
	}
	printf("%d", (arr[n][1]+ arr[n][2]+ arr[n][3]+ arr[n][4]+ arr[n][5]+ arr[n][6]+ arr[n][7]+ arr[n][8]+ arr[n][9])%A);

	return 0;
}