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
int arr[10];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int i, j;//for문변수-->가끔식 long으로
	int n, k;
	int cnt = 0;
	scanf("%d %d", &n, &k);
	for (i = 0; i <n ; i++) {
		scanf("%d", &arr[i]);
	}
	sort(arr, arr + n,greater<int>());
	for (i = 0; i < n; i++) {
		cnt += k / arr[i];
		k %= arr[i];
	}
	printf("%d", cnt);
	return 0;
}