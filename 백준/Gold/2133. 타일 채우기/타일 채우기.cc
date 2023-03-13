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
long long arr[35];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int i, j;//for문변수-->가끔식 long으로
	int n;
	scanf("%d", &n);
	//arr[4] = 11;
	arr[0] = 1;
	arr[2] = 3;
	for (i = 4; i <= n; i += 2) {
		for (j = 1; j <= i / 2; j++) {
			int temp;
			if (j == 1) temp = 3;
			else temp = 2;
			arr[i] += arr[i - 2 * j] * temp;
		}
		//arr[i] = arr[i - 2] * 3 + arr[i - 4] * 2;
	}
	printf("%lld", arr[n]);

	return 0;
}