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
	int n; cin >> n;
	float hak = 0;
	float score = 0;
	map < string, float >m;
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
	for (i = 0; i < n; i++) {
		string sub, s; int a;
		cin >> sub >> a >> s;
		hak += a;
		score += m[s]*a;
	}
	cout << fixed;
	cout.precision(2);
	cout << score / hak;
	//for(i=0;i<n;i++) {}
	//for(i=0;i<n;i++) { for(j=0;j<n;j++) { } }

	return 0;
}