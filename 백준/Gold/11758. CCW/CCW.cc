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
#define pp pair<int,int>
using namespace std;

ll ccw(pp& p1, pp& p2, pp& p3) {
	return (p2.first - p1.first)*(p3.second - p1.second) - (p2.second - p1.second)*(p3.first - p1.first);
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, j; //for문 변수 -> longlong필요한지 확인
	pair<int, int> p[5];
	for (i = 0; i < 3; i++) {
		int a, b; cin >> a >> b;
		p[i] = { a,b };
	}
	if (ccw(p[0], p[1], p[2]) > 0) cout << 1;
	else if (ccw(p[0], p[1], p[2]) < 0) cout << -1;
	else cout << 0;
	return 0;
}