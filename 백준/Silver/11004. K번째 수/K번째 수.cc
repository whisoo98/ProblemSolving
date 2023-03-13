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



using namespace std;

/*struct type_name {

}srt;*/

vector <int> vec;
//stack <type> stk;
//queue <type> q;
//string <type> str;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int i, j;//for문변수-->가끔식 long으로
	int n, m;
	cin >> n >> m;
	for ( i = 0; i < n; i++ )
	{
		int a;
		cin >> a;
		vec.push_back(a);
	}
	sort(vec.begin(), vec.end());
	cout << vec[m - 1];
	return 0;
}