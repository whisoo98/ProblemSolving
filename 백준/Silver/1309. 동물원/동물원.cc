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

int arr[100005][3];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int i, j;//for문변수-->가끔식 long으로
	int n;
	//n = 1;
	//while (1) {
		scanf("%d", &n);
		
		arr[0][0] = 1;
		arr[0][1] = 1;
		arr[0][2] = 1;

		arr[1][0] = 2;
		arr[1][1] = 2;
		arr[1][2] = 3;

		arr[2][0] = 5;
		arr[2][1] = 5;
		arr[2][2] = arr[2][0] + arr[2][1] - arr[1][2];//6
		for (i = 3; i <= n; i++) {
			arr[i][0] = (arr[i - 1][1] % 9901 + arr[i - 1][2] % 9901) ;
			arr[i][1] = (arr[i - 1][0] % 9901 + arr[i - 1][2] % 9901) ;
			arr[i][2] = ((arr[i][0]  + arr[i][1])  - arr[i - 1][2] % 9901) % 9901;
		}
		printf("%d\n", (arr[n][2]) % 9901);
		//n++;
		//if (arr[n][2] < 0 || n>=100000) break;
	
	return 0;
}