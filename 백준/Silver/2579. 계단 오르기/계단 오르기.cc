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

int stair[305];
int arr[305][3];//index칸에 갔을 때 최대값

/*struct type_name {

}srt;*/

//vector <type> vec;
//stack <type> stk;
//queue <type> q;
//string str;
//map <key_type,value_type> m;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int i, j;//for문변수-->가끔식 long으로
	int n;
	cin >> n;
	for ( i = 1; i <= n; i++ )
	{
		cin >> stair[i];
	}
	arr[1][1]=stair[1];
	arr[1][2] = 0;
	arr[2][1] = arr[1][1] + stair[2];
	arr[2][2]=stair[2];
	for ( i = 3; i <= n; i++ )
	{
		arr[i][1] = arr[i - 1][2] + stair[i];
		arr[i][2] = max(arr[i - 2][1], arr[i - 2][2]) + stair[i];
	}
	cout << max(arr[n][1],arr[n][2]);
	return 0;
}