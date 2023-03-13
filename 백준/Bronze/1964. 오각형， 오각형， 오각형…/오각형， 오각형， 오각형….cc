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
#define SUM(n) n*(n+1)/2
#define MOD 45678
using namespace std;




int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, j; //for문 변수 -> longlong필요한지 확인
	ll n; cin >> n;
	if (n == 1) cout << 5;
	else {
		ll term = 7;
		ll tot = 5;
		for (i = 2; i <= n; i++) {
			tot += term;
			term += 3;
			tot %= MOD;
		}
		
		cout << tot;
	}
	
	return 0;
}