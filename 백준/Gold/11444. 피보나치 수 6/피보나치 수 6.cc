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
#define N 1'000'005
//#define N 2'000'000'013
#define MOD 1'000'000'007
#define ll long long
#define endl "\n"
#define MID(a,b) (a+b)/2

using namespace std;
//ll fibo[N];
map<ll, ll> fibo;
ll DNCFibo(ll n) {
	//if (n<=N) return fibo[n];
	if (fibo.count(n)) return fibo[n];
	//cout << n << endl;
	ll a = n / 2;
	/*if (n == 2 * a + 1) {
		a++;
		return fibo[n] = (DNCFibo(a + 1) % MOD*DNCFibo(n - a) % MOD) % MOD + (DNCFibo(a) % MOD*DNCFibo(n - (a + 1) % MOD) % MOD) % MOD;
	}*/
	//if (n % 2 == 0) {
	return fibo[n] = ((DNCFibo(a + 1) % MOD*DNCFibo(n - a) % MOD) % MOD + (DNCFibo(a) % MOD*DNCFibo(n - (a + 1)) % MOD) % MOD) % MOD;
	//}
	//else {
	//		fibo[n] = (DNCFibo())
	//}
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, j; //for문 변수 -> longlong필요한지 확인
	ll n; cin >> n;
	fibo[1] = 1;
	fibo[0] = 0;
	fibo[2] = 1;
	fibo[3] = 2;
	//cout << "!";
	//for (int i = 2; i <= N; i++) fibo[i] = (fibo[i - 1] % MOD + fibo[i - 2] % MOD) % MOD;
	//cout << "!";
	cout << DNCFibo(n) << endl;;
	return 0;
}