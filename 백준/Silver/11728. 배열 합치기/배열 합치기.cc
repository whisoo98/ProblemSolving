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
int arr[2000005];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int i, j;//for문변수-->가끔식 long으로
	int n, m;
	scanf("%d %d", &n, &m);
	//cin >> n >> m;
	for (i = 0; i < n + m; i++) {
		//long long temp;
		scanf("%d", &arr[i]);
		//Set.insert(temp);
	}
	sort(arr, arr + n + m);
	for (i = 0; i < n + m; i++) printf("%d ", arr[i]);
	/*for (auto it = Set.begin(); it != Set.end(); it++) {
		printf("%lld ", *it);
	}*/
	//printf("\n");
	return 0;
}