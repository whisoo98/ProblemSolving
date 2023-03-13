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
long long arr[105];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int i, j;//for문변수-->가끔식 long으로
	arr[1] = 1;
	arr[2] = 1;
	arr[3] = 1;
	int temp;
	int n;
	cin >> n;
	while (n) {
		int m;
		cin >> m;
		if (m <= 3) {
			cout << arr[m]<<endl;
		}
		else {
			for (i = 4; i <= m; i++) arr[i] = arr[i - 2] + arr[i - 3];
			cout << arr[m]<<endl;
		}
	



		n--;
	}

	return 0;
}