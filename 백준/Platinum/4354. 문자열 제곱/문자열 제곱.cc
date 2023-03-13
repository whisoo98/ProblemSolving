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
#define N 1000005
#define ll long long
#define endl "\n"
#define MID(a,b) (a+b)/2

using namespace std;

int pi[N];

void getPi(string s) {
	int len = s.length(), mat = 0, i;
	for (i = 1; i < len; i++) {
		if (s[i] == s[mat]) {
			pi[i] = ++mat;
		}
		else if (mat) {
			i--;
			mat = pi[mat - 1];
		}
	}
}

int kmp(string s) {
	int len = s.length();
	int temp = pi[len - 1];
	int before_temp = temp, before_len = len;
	while (1) {
		if (temp * 2 < len) {
			break;
		}
		before_len = len;
		before_temp = temp;
		
		len = temp;
		temp = pi[temp - 1];
	}
	temp = before_temp;
	len = before_len;
	if (temp * 2 == len) {
		return temp;
	}
	else return -1;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, j; //for문 변수 -> longlong필요한지 확인
	while (1) {
		string s; //cin >> s;
		//cin >> s;
		getline(cin, s);
		if (s == ".") break;
		int L = s.length();
		for (i = 1; i <= L; i++) pi[i] = 0;
		getPi(s);
		int len = kmp(s);

		if (len == -1) cout << 1 << endl;
		else cout << L / len << endl;
	}

	return 0;
}