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

struct inf {
	int age;
	string s;
	int rank;
}srt;

vector <inf> vec;
//stack <type> stk;
//queue <type> q;
//string <type> str;
bool cmp(inf a, inf b)
{
	if ( a.age < b.age ) return true;
	else if ( a.age == b.age )
	{
		if ( a.rank < b.rank ) return true;
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
		cin >> srt.age >> srt.s;
		srt.rank = i;
		vec.push_back(srt);
	}
	sort(vec.begin(), vec.end(), cmp);
	for ( i = 0; i < n; i++ )
	{
		cout << vec[i].age << ' ' << vec[i].s << '\n';

	}

	return 0;
}