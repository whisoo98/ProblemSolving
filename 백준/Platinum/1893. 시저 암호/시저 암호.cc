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
#define N 50005
#define ll long long
#define endl "\n"
#define MID(a,b) (a+b)/2

using namespace std;

int pi[N];
map<char, int> encode;
string alphabet;

void getPi(string s) {
	int len = s.length();
	int mat = 0;
	for (int i = 1; i < len; i++) {
		if (s[i] == s[mat]) {
			pi[i] = ++mat;
		}
		else if (mat) {
			i--;
			mat = pi[mat - 1];
		}
	}
}

int kmp(string s, string cmp, int tried) {
	int len = s.length();
	int len2 = cmp.length();
	int MOD = alphabet.length();
	int mat = 0;
	int ret = 0;

	for (int i = 0; i < len; i++) {
		if (s[i] == alphabet[(encode[cmp[mat]] + tried)%MOD]) {
			mat++;
			if (mat == len2) {
				ret++;
				mat = pi[mat - 1];
			}
		}
		else if (mat) {
			mat = pi[mat - 1];
			i--;
		}
	}
	return ret;
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, j; //for문 변수 -> longlong필요한지 확인
	int T; cin >> T;
	while (T--) {
		int cnt = 0;
		cin >> alphabet;

		int len = alphabet.length();
		for (i = 0; i < len; i++) {
			encode[alphabet[i]] = i;
		}
		string origin; cin >> origin;
		getPi(origin);
		int l = origin.length();
		string s; cin >> s;
		vector<int> ans;
		for (i = 0; i < len; i++) {
			int ret = kmp(s, origin, i);
			if (ret == 1) {
				cnt++;
				//ans = i;
				ans.push_back(i);
			}
		}

		if (cnt == 0) cout << "no solution" << endl;
		else if (cnt == 1) {
			cout << "unique: " << ans[0] << endl;
		}
		else {
			cout << "ambiguous: ";
			for (auto it : ans) cout << it << " ";
			cout << endl;
		}


		for (i = 1; i < l; i++) {
			pi[i] = 0;
		}
		encode.clear();
	}


	return 0;
}