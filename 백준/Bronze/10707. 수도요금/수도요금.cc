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
	int costX, baseY, upperY, costY, tot;
	cin >> costX >> baseY >> upperY >> costY >> tot;
	int X = tot * costX;
	int Y=0;
	if (tot <= upperY) {
		Y += baseY;
	}
	else {
		Y += baseY;
		Y += (tot - upperY)*costY;
	}
	cout << min(X, Y);



	return 0;
}