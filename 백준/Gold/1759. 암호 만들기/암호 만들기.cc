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
string jaum = "bcdfghjklmnpqrstvwxyz";
string moum = "aeiou";
string s;
int n, possible;
vector<string> v;
vector<string>ans;
string temp;
void dfs(int lv) {
	if (lv == possible) {
		if (temp.size() == n) {
			v.push_back(temp);
			return;
		}
		return;
	}
	temp += s[lv];
	dfs(lv + 1);
	temp.erase(temp.size() - 1);
	dfs(lv + 1);
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int i, j;//for문변수-->가끔식 long으로
	//scanf("%d %d", &n, &possible);
	cin >> n >> possible;
	for (i = 0; i < possible; i++) {
		char c;
		cin >> c;
		s += c;
	}
	
	sort(s.begin(), s.end());
	dfs(0);
	for (i = 0; i < v.size(); i++) {
		int cnt = 0;
		for (j = 0; j < n; j++) {
			for (int k = 0; k < 5; k++) {
				if (v[i][j] == moum[k]) cnt++;
			}
		}
		if (cnt >= 1 && cnt <= n - 2) cout << v[i] << "\n";
	}
	return 0;
}