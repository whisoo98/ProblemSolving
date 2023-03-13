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
	int h, m, s; cin >> h >> m >> s;
	int Time; cin >> Time;
	int tot = h * 3600 + m * 60 + s;
	tot += Time;
	if (tot >= 86400) {
		tot %= 86400;
	}
	//cout << tot / 3600 << " " << tot % 60;
	h = tot / 3600;
	tot %= 3600;
	m = tot / 60;
	s = tot % 60;
	cout << h << " " << m << " " << s;
	return 0;
}