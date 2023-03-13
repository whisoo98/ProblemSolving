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

struct Resist {
	const char* color;
	long long value;
	long long multy;
};

//vector <type> vec;
//stack <type> stk;
//queue <type> q;
//string str;
//map <key_type,value_type> m;
int main()
{
	Resist res[10] = {
		{"black",0,1},
		{"brown",1,10},
		{"red",2,100},
		{"orange",3,1000},
		{"yellow",4,10000},
		{"green",5,100000},
		{"blue",6,1000000},
		{"violet",7,10000000},
		{"grey",8,100000000},
		{"white",9,1000000000} };
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int i, j;//for문변수-->가끔식 long으로
	string s;
	int arr[3];
	for (i = 0; i < 3; i++) {
		cin >> s;
		for (j = 0; j < 10; j++) {
			if (s == res[j].color) arr[i] = j;
		}
	}
	printf("%lld", (res[arr[0]].value*10 + res[arr[1]].value)*res[arr[2]].multy);
	//cin >> s;
	

	return 0;
}