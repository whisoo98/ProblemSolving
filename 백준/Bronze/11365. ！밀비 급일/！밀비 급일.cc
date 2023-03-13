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
	string end = "END";
	string endline = "\n";
	while(1) {
		string s; getline(cin, s);
		if (s == end) return 0;
		stack<char> stk;
		stk.push('\n');
		for (i = 0; i < s.length() && s[i] != endline[0]; i++) {
			stk.push(s[i]);
		}
		while (!stk.empty()) {
			cout << stk.top();
			stk.pop();
		}
	}

	//for(i=0;i<n;i++) {}
	//for(i=0;i<n;i++) { for(j=0;j<n;j++) { } }

	return 0;
}