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
	int a, b; cin >> a;
	int mok, rest;
	pair<int, int> first;
	mok = a / 4; rest = a % 4;
	if (rest == 0) {
		rest = 4;
		mok--;
	}
	first = { mok,rest };
	
	cin >> a;
	pair<int, int> second;
	mok = a / 4; rest = a % 4;
	if (rest == 0) {
		rest = 4;
		mok--;
	}
	second = { mok,rest };

	int dist = abs(first.first - second.first) + abs(second.second - first.second);
	cout << dist;
	return 0;
}