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
	int len = s.length();
	int mat = 0;
	for (int i = 1; i < len; i++) {
		if (s[i] == s[mat]) {
			pi[i] = ++mat;
		}
		else if (mat != 0) {
			i--;
			mat = pi[mat - 1];
		}
	}
}

int kmp(string target, string to_find) {
	int len1 = target.length(), len2 = to_find.length();
	int mat = 0;
	int cnt = 0;
	for (int i = 0; i < len1; i++) {
		if (target[i] == to_find[mat]) {
			if (++mat == len2) {
				//complete
				cnt++;
				mat = pi[mat - 1];
			}
		}
		else if (mat != 0) {
			i--;
			mat = pi[mat - 1];
		}
	}
	return cnt;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, j; //for문 변수 -> longlong필요한지 확인
	int L; cin >> L;
	string s; cin >> s;
	getPi(s);
	int len = s.length();
	int cmp = -1;
	/*for (i = 1; i <= s.length(); i++) {
		cmp = max(cmp, pi[i]);
	}/*/
	cmp = pi[s.length() - 1];
	if (cmp * 2 > len) {
		cout << (len - cmp * 2) + cmp;
	}
	else {
		cout << (len - cmp * 2) + cmp;
	}
	
	return 0;
}