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
	int a, b; cin >> a >> b;
	if (a < 0) {
		if (b < 0) {
			cout << 3;
		}
		else {
			cout << 2;
		}
	}
	else {
		if (b < 0) {
			cout << 4;
		}
		else {
			cout << 1;
		}
	}

	return 0;
}