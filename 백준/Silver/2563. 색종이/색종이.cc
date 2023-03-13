#include <cstdio>
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
#include <climits>
#include <cstring>


using namespace std;

/*struct type_name {

}srt;*/

//vector <type> vec;
//stack <type> stk;
//queue <type> q;
//string str;
//map <key_type,value_type> m;
int arr[105][105];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int i, j;//for문변수-->가끔식 long으로
	int n; scanf("%d", &n);
	for (i = 0; i < n; i++) {
		int x, y; scanf("%d %d", &x, &y);
		for (j = 0; j < 10; j++) {
			for (int k = 0; k < 10; k++) {
				arr[y + j][x + k] = 1;
			}
		}
	}
	int chk = 0;
	for (i = 1; i <= 100; i++) {
		for (j = 1; j <= 100; j++) {
			if (arr[i][j]) chk++;
		}
	}
	printf("%d", chk);
	//for(i=0;i<n;i++) { for(j=0;j<n;j++) { } }

	return 0;
}