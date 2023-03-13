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
	string s, k;
	string temp;
	cin >> s >> k;
	int len = s.length();
	for (i = 0; i < len; i++) {
		if (s[i] >= '0' && s[i] <= '9') {
			continue;
		}
		else {
			temp += s[i];
		}
	}
	if (temp.find(k) != string::npos) {
		cout << 1;
	}
	else {
		cout << 0;
	}
	//for(i=0;i<n;i++) {}
	//for(i=0;i<n;i++) { for(j=0;j<n;j++) { } }

	return 0;
}