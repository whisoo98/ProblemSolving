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

vector<pair<int, int>> ans;

void query(int len, int n) {
	if (len <= 1) return;
	int length = len;
	int L = len;
	int tlen = len;
	int chk = 0;
	while (len != 1) {
		tlen = len;
		len = pi[len - 1];
		if (len * 2 == tlen) {
			L = len;
			break;
		}
		else if (len * 2 < tlen) {
			chk = 1;
			break;
		}
	}
	if (chk == 1 && L != len) {
		query(L - 1, n);
	}
	else {
		for (int i = len * 2; i <= length; i += len) {
			ans.push_back({ i,i / len });
		}
		query(L - 1, n);
	}


}

int asc[200];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, j; //for문 변수 -> longlong필요한지 확인
	for (i = 97; i <= 126; i++) {
		asc[i] = 1;
	}
	int t = 1;
	while (1) {
		int n; cin >> n;
		if (n == 0) break;
		string s; cin >> s;
	
		getPi(s);
		cout << "Test case #" << t << endl;
		query(s.length(), n);


		sort(ans.begin(), ans.end());
		for (auto it : ans) {
			cout << it.first << " " << it.second<<endl;
		}

		cout << endl;
		t++;

		for (i = 1; i < n; i++) {
			pi[i] = 0;
		}
		ans.clear();
	}

	return 0;
}