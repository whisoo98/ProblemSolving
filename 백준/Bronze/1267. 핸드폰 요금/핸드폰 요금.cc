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




int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, j; //for문 변수 -> longlong필요한지 확인
	int n; cin >> n;
	int m = 0, y = 0;
	for (i = 1; i <= n; i++) {
		int a; cin >> a;
		int mok, rest;
		
		mok = a / 30;
		rest = a % 30;
		mok++;
		y += mok * 10;

		mok = a / 60;
		rest = a % 60;
		mok++;
		m += mok * 15;
	}
	if (y < m) {
		cout << "Y " << y;
	}
	else if (m < y)cout << "M " << m;
	else cout << "Y M " << y;
	return 0;
}