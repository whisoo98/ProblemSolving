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
#include<deque>

using namespace std;

/*struct type_name {

}srt;*/

vector <int> vec(105);
//stack <type> stk;
//queue <type> q;
//string str;
//map <key_type,value_type> m;
int arr[105];
//deque<int> deq;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int i, j;//for문변수-->가끔식 long으로
	int n;
	scanf("%d", &n);
	for (i = 1; i <= n; i++) scanf("%d", &arr[i]);
	//vec.push_back(1);
	for (i = 1; i <= n; i++) {
		vec.insert(vec.begin() + arr[i], i);
	}
	for (i = n - 1; i >= 0; i--) printf("%d ", vec[i]);

	return 0;
}