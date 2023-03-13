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
	int hap, cha; cin >> hap >> cha;
	
	//hap = a+b cha = a-b
	int a, b;
	a = (hap + cha) / 2;
	b = (hap - cha) / 2;
	int Hap, Cha;
	Hap = (a + b);
	Cha = (a - b);
	if (a < 0 || b < 0) {
		cout << -1;
		return 0;
	}
	if (Hap == hap && Cha == cha) cout << a << " " << b;
	else cout << -1;
	return 0;
}