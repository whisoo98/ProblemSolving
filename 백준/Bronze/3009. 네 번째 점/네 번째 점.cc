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
#define N 100005
#define ll long long
#define endl "\n"
#define MID(a,b) (a+b)/2

using namespace std;
int x[5], y[5];


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, j; //for문 변수 -> longlong필요한지 확인
	for (i = 1; i <= 3; i++) {
		cin >> x[i] >> y[i];
	}
	sort(x + 1, x + 1 + 3);
	sort(y + 1, y + 1 + 3);
	if (x[2] != x[1]) {
		cout << x[1] << " ";
	}
	else cout << x[3] << " ";
	if (y[2] != y[1]) {
		cout << y[1] << " ";
	}
	else cout << y[3] << " ";
	return 0;
}