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
int arr[105];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int i, j;//for문변수-->가끔식 long으로
	int T;
	scanf("%d", &T);
	while (T--) {
		int n;
		scanf("%d", &n);
		for (i = 1; i <= n; i++) arr[i] = 0;
		for (i = 1; i <= n; i++) {
			for (j = i; j <= n; j += i) {
				if (!arr[j]) arr[j] = 1;
				else arr[j] = 0;
			}
		}
		int chk = 0;
		for (i = 1; i <= n; i++) {
			if (arr[i]) chk++;
		}
		printf("%d\n", chk);
	}

	return 0;
}