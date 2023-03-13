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
#define N 5005
#define ll long long
#define endl "\n"
#define MID(a,b) (a+b)/2

using namespace std;

int pi[N][N];
int m = 0;
void getPi(string s) {
	int len = s.length(), mat = 0, i;
	for (i = 1; i < len; i++) {
		mat = 0;
		for (int j = i; j < len; j++) {
			if (s[j] == s[mat+i-1]) {
				pi[i][j] = ++mat;
				m = max(m, pi[i][j]);
			}
			else if (mat != 0) {
				j--;
				mat = pi[i][mat +(i-1)- 1];
			}
		}
	}
}

void kmp(string s) {
	int len = s.length();
	int mat = 0;
	int cnt = 0;
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, j; //for문 변수 -> longlong필요한지 확인
	string s; cin >> s;
	int len = s.length();
	getPi(s);
	//kmp(s);
	/*for (i = 1; i <= len; i++) {
		for (j = 1; j <= len; j++) {
			m = max(m, pi[i][j]);
		}
	}*/
	cout << m;

	return 0;
}