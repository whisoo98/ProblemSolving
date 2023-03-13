#include <cstdio>
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
#include <climits>
#include <cstring>
#include <cmath>
#include <sstream>


using namespace std;

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
	//int n; scanf("%d", &n);
	string s; cin >> s;
	
	
	map < string, double >m;
	m.insert({ "A+",4.3 });
	m.insert({ "A0",4.0 });
	m.insert({ "A-",3.7 });
	m.insert({ "B+",3.3 });
	m.insert({ "B0",3.0 });
	m.insert({ "B-",2.7 });
	m.insert({ "C+",2.3 });
	m.insert({ "C0",2.0 });
	m.insert({ "C-",1.7 });
	m.insert({ "D+",1.3 });
	m.insert({ "D0",1.0 });
	m.insert({ "D-",0.7 });
	m.insert({ "F",0.0 });
	cout.precision(1);
	cout << fixed;
	cout << m[s];
	return 0;
}