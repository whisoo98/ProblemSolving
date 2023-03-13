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
	int min = 0, man = 0;

	for (j = 1; j <= 4; j++) {
		int a; cin >> a;
		min += a;
	}
	for (j = 1; j <= 4; j++) {
		int a; cin >> a;
		man += a;
	}
	if (min >= man)cout << min;
	else cout << man;
	return 0;
}