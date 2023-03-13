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
string s;
string cmp;

void getPi() {
	int len = cmp.length();
	int mat = 0;
	int i;
	for (i = 1; i < len; i++) {
		if (cmp[i] == cmp[mat]) {
			pi[i] = ++mat;
		}
		else if (mat) {
			mat = pi[mat - 1];
			i--;
		}
	}
}
int cnt;
vector<int> v;
void kmp() {
	int len1 = s.length();
	int len2 = cmp.length();
	int mat = 0;
	
	int i;
	for (i = 0; i < len1; i++) {
		if (s[i] == cmp[mat]) {
			mat++;
			if (mat == len2) {
				//cout << (i+1)-mat+1<< endl;
				v.push_back((i + 1) - mat + 1);
				cnt++;
				mat = pi[mat - 1];
				//i--;
			}
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
	getline(cin, s);
	//cin >> cmp;
	getline(cin, cmp);
	getPi();
	kmp();
	cout << cnt << endl;
	for (auto it : v) {
		cout << it << " ";
	}
	return 0;
}