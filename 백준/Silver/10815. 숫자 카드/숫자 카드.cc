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
int arr[500005];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int i, j;//for문변수-->가끔식 long으로
	int n,m; scanf("%d", &n);


	for (i = 0; i < n; i++) { scanf("%d", &arr[i + 1]); }
	sort(arr + 1, arr + 1 + n);
	scanf("%d", &m);
	for (i = 0; i < m; i++) {
		int ans; scanf("%d", &ans);
		int left = 1, right = n;
		while (left <= right) {
			int mid = (left + right) / 2;
			if (ans > arr[mid]) {
				left = mid + 1;
			}
			else if (ans < arr[mid]) {
				right = mid - 1;
			}
			else {
				right = mid;
				break;
			}
		}
		if (ans == arr[right]) {
			printf("1 ");
		}
		else printf("0 ");

	}

	//for(i=0;i<n;i++) { for(j=0;j<n;j++) { } }

	return 0;
}