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
#define N 55
#define ll long long
#define endl "\n"
#define MID(a,b) (a+b)/2

using namespace std;


char dir[N];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, j; //for문 변수 -> longlong필요한지 확인
	int n; cin >> n;
	string origin; cin >> origin;
	int len = origin.length();

	
	for (i = 2; i <= n; i++) {
		string s; cin >> s;
		for (j = 0; j < len; j++) {
			if (s[j] != origin[j]) dir[j] = '?';
		}
	}
	for (i = 0; i < len; i++) {
		if (dir[i] != '?') cout << origin[i];
		else cout << '?';
	}
	return 0;
}