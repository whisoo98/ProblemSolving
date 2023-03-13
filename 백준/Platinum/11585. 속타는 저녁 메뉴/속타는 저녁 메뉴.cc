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
int arr[N];
 
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

int kmp(string s, string meat) {
	s += s;
	int len1 = s.length();
	int len2 = meat.length();
	int mat = 0;
	int ret = 0;
	for (int i = 0; i < len1-1; i++) {
		if (s[i] == meat[mat]) {
			mat++;
			if (mat == len2) {
				ret++;
				mat = pi[mat-1];
			}
		}
		else if(mat){
			mat = pi[mat - 1];
			i--;
		}
	}
	return ret;
}

int gcd(int a, int b) {
	if (b == 0) return a;
	return gcd(b, a%b);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, j; //for문 변수 -> longlong필요한지 확인
	int n; cin >> n;
	string s = "";
	string meat = "";
	for (i = 1; i <= n; i++) {
		string temp; cin >> temp;
		s += temp;
		arr[i - 1] = i - 1;
	}

	for (i = 1; i <= n; i++) {
		string temp; cin >> temp;
		meat += temp;
	}
	//cout << s << endl << meat << endl;
	getPi(meat);
	int cnt = 0;
	cnt = kmp(s, meat);
	int GCD = gcd(cnt, n);
	cout << cnt / GCD << "/" << n / GCD;
	return 0;
}