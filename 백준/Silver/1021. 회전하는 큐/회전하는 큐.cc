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

//vector <type> vec;
//stack <type> stk;
//queue <type> q;
//string str;
//map <key_type,value_type> m;
deque<int> deq;
int arr[55];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int i, j;//for문변수-->가끔식 long으로
	int n, m;
	cin >> n >> m;
	int chk = 0;
	for (i = 1; i <= n; i++) deq.push_back(i);
	for (i = 1; i <= m; i++) cin >> arr[i];
	i = 1;
	while (i <= m) {
		for (j = 0; j < n; j++) {
			if (arr[i] == deq[j]) break;
		}
		if (j <= n / 2) {
			if (arr[i] == deq.front()) {
				deq.pop_front();
				i++;
				n--;
			}
			else {
				deq.push_back(deq.front());
				deq.pop_front();
				chk++;
			}
		}
		else {

			deq.push_front(deq.back());
			deq.pop_back();
			chk++;

		}
	}
	cout << chk;
	return 0;
}