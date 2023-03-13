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
int arr[1005][6];
int temp[1005];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int i, j;//for문변수-->가끔식 long으로
	int n;
	cin >> n;
	for (i = 0; i < n; i++) {
		for (j = 0; j < 5; j++) {
			cin >> arr[i][j];
		}
	}
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			if (i == j) continue;
			for (int k = 0; k < 5; k++) {

				if (arr[i][k] == arr[j][k]) {
					arr[i][5]++;
					break;
				}
			}
		}
		temp[i] = arr[i][5];
	}
	sort(temp, temp + n, greater<int>());
	for (i = 0; i < n; i++) {
		if (temp[0] == arr[i][5]) {
			cout << i+1;
			break;
		}
	}


	return 0;
}