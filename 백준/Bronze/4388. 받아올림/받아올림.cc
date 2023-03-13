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
	while (1) {
		ll a, b; cin >> a >> b;
		if (a == 0 && b == 0) break;
		int cnt = 0;
		ll chk = 0;
		while (a||b) {
			ll t1 = a % 10, t2 = b % 10;
			a /= 10, b /= 10;
			if (t1 + t2 + chk >= 10) {
				cnt++;
				chk = 1;
			}
			else chk = 0;
		}
		cout << cnt << endl;
	}

	return 0;
}