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

int arr[1005][10];//첫 인덱스 숫자 길이 두번째 인덱스 시작 숫자

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int i, j;//for문변수-->가끔식 long으로
	int n;
	scanf("%d", &n);
	for (i = 0; i < 10; i++) arr[1][i] = 1;
	for (i = 2; i <= n; i++) {
		for (j = 0; j < 10; j++) {
			for (int k = j; k < 10; k++) {
				arr[i][j] = (arr[i][j] + arr[i - 1][k])%10007;
			}
		}
	}
	printf("%d", (arr[n][0] + arr[n][1] + arr[n][2] + arr[n][3] + arr[n][4] + arr[n][5] + arr[n][6] + arr[n][7] + arr[n][8] + arr[n][9]) % 10007);

	return 0;
}