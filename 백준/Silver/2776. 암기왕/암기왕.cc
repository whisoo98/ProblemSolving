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
int arr1[1000005];
//int arr2[1000005];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int i, j;//for문변수-->가끔식 long으로
	int T;
	scanf("%d", &T);
	while (T--) {
		int n, m;
		scanf("%d", &n);
		for (i = 0; i < n; i++) {
			//		int temp;
			scanf("%d", &arr1[i]);
			//		arr1[temp]++;	
		}
		sort(arr1, arr1 + n);
		scanf("%d", &m);
		for (i = 0; i < m; i++) {
			int temp;
			scanf("%d", &temp);
			if (binary_search(arr1, arr1 + n, temp)) printf("1\n");
			else printf("0\n");

		}

	}
	return 0;

}