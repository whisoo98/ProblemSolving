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
#include<set>

using namespace std;

/*struct type_name {

}srt;*/
//multiset<int> m;
//vector <type> vec;
//stack <type> stk;
//queue <type> q;
//string str;
//map <key_type,value_type> m;
int arr[10001];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int i, j;//for문변수-->가끔식 long으로
	int n;
	cin >> n;
	int temp;
	for (i = 0; i < n; i++) {
		cin >> temp;
		arr[temp]++;
	}
	j = 0;
	for (i = 0; i < 10000; i++) {
		j++;
		while (arr[j]) {
			cout << j << "\n";
			arr[j]--;
		}
	}

	return 0;
}