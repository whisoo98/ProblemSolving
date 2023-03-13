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

/*struct <type> {

}srt;*/

vector <int> vec;
vector <int> target;

/*stack <type> stk;*/
/*queue <type> q;*/
/*string <type> str;*/
void search(int n,int a)
{
	int chk = 0;
	int f, b;
	f = 0;
	b = n-1;
	while ( f < b )
	{
		int mid = (f + b) / 2;
		if ( vec[mid] < a )
		{
			f = mid+1;
		}
		else if ( vec[mid] > a )
		{
			b = mid-1; 
		}
		else if ( vec[mid] == a )
		{
			cout << '1' << '\n';
			chk++;
			break;
		}
	}
	
	if ( chk == 0 )
	{
		if ( vec[f] == a )
		{
			cout << '1' << '\n';
		}
		else cout << '0' << '\n';
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int i, j;//for문변수-->가끔식 long으로
	int n;
	cin >> n;
	int a;
	int f, b;
	for ( i = 1; i <= n; i++ )
	{
		cin >> a;
		vec.push_back(a);
	}
	int m;
	sort(vec.begin(), vec.end());

	cin >> m;
	for ( i = 1; i <= m; i++ )
	{
		cin >> a;
		target.push_back(a);
		search(n,a);
	}

	return 0;
}