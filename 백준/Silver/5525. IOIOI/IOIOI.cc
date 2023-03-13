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
#define N 
#define ll long long
#define endl "\n"
#define MID(a,b) (a+b)/2

using namespace std;

void Solution(int n, int len, string s) {
	string PN = "IOI";
	for (int i = 2; i <= n; i++) {
		PN += "OI";
	}
	int cnt = 0;
	int idx = 0;
	while (1) {
		idx = s.find(PN,idx);
		if (idx == string::npos) break;
		cnt++;
		idx += 2;
	}
	cout << cnt << endl;
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, j; //for문 변수 -> longlong필요한지 확인
	int n; cin >> n;
	int len; cin >> len;
	string s; cin >> s;
	Solution(n, len, s);
	return 0;
}