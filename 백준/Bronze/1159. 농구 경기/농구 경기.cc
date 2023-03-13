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

/*struct type_name {

}srt;*/

//vector <type> vec;
//stack <type> stk;
//queue <type> q;
//string str;
//map <key_type,value_type> m;
string s = "abcdefghijklmnopqrstuvwxyz";
int arr[30];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int i, j;//for문변수-->가끔식 long으로
	int n;
	string str;
	cin >> n;
	for (i = 0; i < n; i++) {
		cin >> str;
		for (j = 0; j < s.length(); j++) {
			if (str[0] == s[j]) arr[j]++;
		}
	}
	int cnt = 0;
	for (i = 0; i < s.length(); i++) {
		if (arr[i] >= 5) {
			cout << s[i];
			cnt++;
		}
	}
	if (!cnt) cout << "PREDAJA";
	return 0;
}