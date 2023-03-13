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
#define N 1'000'005
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
		else if (mat) {
			mat = pi[mat - 1];
			i--;
		}
	}
}

bool kmp(string s, string cmp) {
	int len = s.length();
	int len2 = cmp.length();
	int mat = 0;
	bool chk = 0;
	for (int i = 0; i < len; i++) {
		if(s[i]==cmp[mat]){
			if (++mat == len2) {
				chk++;
				break;
			}
		}
		else if (mat) {
			i--;
			mat = pi[mat - 1];
		}
	}
	return chk;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, j; //for문 변수 -> longlong필요한지 확인
	string s; cin >> s;
	string cmp; cin >> cmp;

	getPi(cmp);
	cout << kmp(s, cmp);

	return 0;
}