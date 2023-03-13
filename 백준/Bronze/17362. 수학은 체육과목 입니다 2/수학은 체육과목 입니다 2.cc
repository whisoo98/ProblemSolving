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
	int mok = n / 4;
	int rest = n % 4;
	if (rest) {
		mok++;
		rest = rest - 4;
		if (mok % 2) {
			cout << 4 + rest;
		}
		else {
			cout << 2 - rest;
		}
		return 0;
	}
	else {
		if (mok % 2) {
			cout << 4;
		}
		else cout << 2;
		return 0;
	}
	return 0;
}