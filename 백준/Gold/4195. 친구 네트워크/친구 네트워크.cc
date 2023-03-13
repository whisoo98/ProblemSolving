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
map <string,string> m; //key == child, value == parent
map <string, int> height;
string Find(string s) {
	if (s == m[s]) return s;
	else return m[s]=Find(m[s]);
}
void Union(string S1, string S2) {
	string s1 = Find(S1);
	string s2 = Find(S2);
	if (s1 == s2) return;
	if (height[s1] == height[s2]) {
		height[s1] += height[s2];
	//	m.insert(make_pair(s2, s1));
		m[s2] = s1;
		return;
	}
	else if (height[s1] > height[s2]) {
		height[s1] += height[s2];
		//m.insert(make_pair(s2, s1));
		m[s2] = s1;
		return;
	}
	else {
		height[s2] += height[s1];
		//m.insert(make_pair(s1, s2));
		m[s1] = s2;
		return;
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int i, j;//for문변수-->가끔식 long으로
	int T;
	scanf("%d", &T);
	while (T--) {
		int num_friend;
		scanf("%d", &num_friend);
		m.clear();
		height.clear();

		for (i = 0; i < num_friend; i++) {
			char s1[25], s2[25];
			scanf("%s %s", s1, s2);
			if (m.find(s1) == m.end()) m.insert(make_pair(s1, s1));
			if (m.find(s2) == m.end()) m.insert(make_pair(s2, s2));
			if (height.find(s1) == height.end()) {
				height.insert(make_pair(s1, 1));
			}
			if (height.find(s2) == height.end()) {
				height.insert(make_pair(s2, 1));
			}
			Union(s1, s2);
			printf("%d\n", max(height[Find(s2)], height[Find(s1)]));
		}


	}


	return 0;
}