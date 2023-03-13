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
string s;
vector<string>ans;
//vector<string>ans[85];
int n;
void back(int lev) {
	if (ans.empty()) {
		for (int i = 0; i < lev; i++) {
			for (int j = 1; j <= lev / 2 && i + j <= lev; j++) {
				if (s.substr(i, j) == s.substr(i + j, j)) {
					return;
				}
			}
		}

		if (n == lev) { ans.push_back(s); return; }
		/*else if (!lev) {

			s += "1";
			back(lev + 1);
			s.erase(s.end() - 1);

			s += "2";
			back(lev + 1);
			s.erase(s.end() - 1);

			s += "3";
			back(lev + 1);
			s.erase(s.end() - 1);

		}
		else {
			if (s.back() != '1') {
				s += "1";
				back(lev + 1);
				s.erase(s.end() - 1);
			}

			if (s.back() != '2') {
				s += "2";
				back(lev + 1);
				s.erase(s.end() - 1);
			}

			if (s.back() != '3') {
				s += "3";
				back(lev + 1);
				s.erase(s.end() - 1);
			}
		}*/
		//int chk = 0;
		else {
			s += "1";
			back(lev + 1);
			s.erase(s.end() - 1);

			s += "2";
			back(lev + 1);
			s.erase(s.end() - 1);

			s += "3";
			back(lev + 1);
			s.erase(s.end() - 1);

		}
	}
	else return;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int i, j;//for문변수-->가끔식 long으로
	scanf("%d", &n);
	back(0);
	//cout << "!";
	//for(i=0;i<n;i++) {}
	//for(i=0;i<n;i++) { for(j=0;j<n;j++) { } }
	sort(ans.begin(), ans.end());
	cout << ans[0];
	return 0;
}