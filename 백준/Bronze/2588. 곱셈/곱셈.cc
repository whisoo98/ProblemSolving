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
	int temp = b;
	int h, t, o;
	o = b % 10;
	b /= 10;
	t = b % 10;
	b /= 10;
	h = b;
	cout << a * o << endl << a * t << endl << a * h << endl << a * temp;
	return 0;
}