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


//stack <type> stk;
//queue <type> q;
string str;
vector <string> vec;
int cmp(string a, string b)
{
	if ( a.size() < b.size() ) return true;
	else if ( a.size() == b.size() )
	{
		if ( a < b ) return true;
		else if ( a == b )
		{
			return false;
		}
		else return false;
	}
	else return false;


}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int i, j;//for문변수-->가끔식 long으로
	int n;
	cin >> n;
	for ( i = 0; i < n; i++ )
	{
		cin >> str;
		vec.push_back(str);
	}
	sort(vec.begin(), vec.end(), cmp);
	vec.resize(vec.size() + 1);
		for ( i = 0; i < n; i++ )
	{
		if ( vec[i] == vec[i + 1] ) continue;
		else	cout << vec[i] << '\n';

	}
	return 0;
}