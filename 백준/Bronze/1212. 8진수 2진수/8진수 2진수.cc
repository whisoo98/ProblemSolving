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

using namespace std;

char eight[10][10] = {
	"000",
	"001",
	"010",
	"011",
	"100",
	"101",
	"110",
	"111",
};
string num = "0123456789";

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, j; //for문 변수 -> longlong필요한지 확인
	string s; cin >> s;
	if (s == "0") {
		cout << 0;
		return 0;
	}
	string ans;
	for (auto it : s) {
		for (i = 0; i < 10; i++) {
			if (it == num[i]) {
				ans += eight[i];
			}
		}
	}
	int pos = ans.find_first_of("1");
	int len = ans.length();
	for (i = pos; i < len; i++) {
		cout << ans[i];
	}
	return 0;
}