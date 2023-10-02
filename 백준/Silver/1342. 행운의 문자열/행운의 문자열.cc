#include <iostream>
#include <algorithm>
#include <functional>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <string>
#include <queue>
#include <stack>
#include <map>
#include <vector>
#include <set>
#include <sstream>
#include <ctime>
#include <climits>
#include <tuple>
#define N 30
#define ll long long
#define endl "\n"
#define MID(a,b) (a+b)/2

using namespace std;

ll ans;
map<char, int> alphabet;
vector<char> v;
string s;
void dfs_lucky_string(char last, int len) {
	if (len == s.length()) {
		ans++;
		return;
	}
	for (auto it : v) {
		if (last != it && alphabet[it]) {
			alphabet[it]--;		
			dfs_lucky_string(it,len+1);
			alphabet[it]++;
		}
	}
}

void Solution() {
	/*int one = 1;
	for (auto it : alphabet) {
		if (it.second != 1) {
			one = 0;
			break;
		}
	}
	if (one) {

	}*/
	for (auto it : v) {
		alphabet[it]--;
		string lucky_string = "";
		//lucky_string += it;
		dfs_lucky_string(it,1);
		alphabet[it]++;
	}
	cout << ans << endl;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, j; //for문 변수 -> longlong필요한지 확인
	cin >> s;
	for (int i = 0; i < s.length(); i++) {
		if (alphabet.count(s[i]) == 0) {
			alphabet[s[i]] = 1;
			v.push_back(s[i]);
		}
		else {
			alphabet[s[i]] += 1;
		}
	}
	Solution();

	return 0;
}