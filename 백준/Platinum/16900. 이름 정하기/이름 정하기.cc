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
#define N 500'005
#define ll long long
#define endl "\n"
#define MID(a,b) (a+b)/2

using namespace std;

ll pi[N];

void getPi(string s) {
	int len = s.length();
	ll mat = 0;

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


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, j; //for문 변수 -> longlong필요한지 확인
	string s; ll n; cin >> s >> n;
	ll len = s.length();
	getPi(s);
	cout << len*n - pi[len-1] * (n-1);

	return 0;
}