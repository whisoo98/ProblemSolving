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
int arr[1000005];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int i, j;//for문변수-->가끔식 long으로
	int n;
	cin >> n;
	for (i = 1; i < 1000005; i++) arr[i] = 1e9;
	arr[n] = 0;
	queue<int>q;
	q.push(n);
	while (!q.empty()) {
		int now = q.front();
		if (now == 1) {
			cout << arr[now];
			return 0;
		}
		q.pop();
		if (now % 3 == 0 && arr[now / 3] > arr[now] + 1) {
			arr[now / 3] = arr[now] + 1;
			q.push(now / 3);
		}
		if (now % 2 == 0 && arr[now / 2] > arr[now] + 1) {
			arr[now / 2] = arr[now] + 1;
			q.push(now / 2);
		}
		if (arr[now - 1] > arr[now] + 1) {
			arr[now - 1] = arr[now] + 1;
			q.push(now - 1);
		}		
	}
	return 0;
}