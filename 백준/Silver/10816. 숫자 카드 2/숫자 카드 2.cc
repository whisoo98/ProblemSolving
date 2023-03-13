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

//stack <type> stk;
//queue <type> q;
//string str;
//map <key_type,value_type> m;
int arr[20000005];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int i, j;//for문변수-->가끔식 long으로
	int n;
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		int temp;
		scanf("%d", &temp);
//		vec.push_back(temp);
		arr[temp + 10000000]++;
	}
	int m;
	scanf("%d", &m);
	for (i = 0; i < m; i++) {
		int temp;
		scanf("%d", &temp);
		printf("%d ",arr[temp+ 10000000]);
	}

	return 0;
}