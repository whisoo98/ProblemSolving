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
#define N 50
#define ll long long
#define endl "\n"
#define MID(a,b) (a+b)/2

using namespace std;
string num_to_string[N];


void preProcess() {
	for (int i = 0; i < 10; i++) {
		num_to_string[i] = '0' + i;
	}
	for (int i = 10; i < 36; i++) {
		num_to_string[i] = 'A' + (i - 10);
	}
}

string convertBase(int n, int base) {
	string ret = "";
	while (n) {
		int rest = n % base;
		n /= base;
		ret += num_to_string[rest];
	}
	reverse(ret.begin(), ret.end());
	return ret;
}

void Solution(int n, int base) {
	string s;
	preProcess();
	s = convertBase(n, base);
	cout << s << endl;
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, j; //for문 변수 -> longlong필요한지 확인
	int n; cin >> n;
	int base; cin >> base;
	Solution(n, base);
	return 0;
}