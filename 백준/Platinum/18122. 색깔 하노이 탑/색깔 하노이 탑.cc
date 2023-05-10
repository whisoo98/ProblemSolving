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
#define ll long long
#define endl "\n"
#define MID(a,b) (a+b)/2
#define MOD 1'000'000'007
#define R 0
#define B 1
#define BB 2
using namespace std;


ll hanoi[N][3];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, j; //for문 변수 -> longlong필요한지 확인
	int n; cin >> n;
	hanoi[1][R] = 1;
	hanoi[1][B] = 3;
	hanoi[1][BB] = 2;

	hanoi[2][R] = 5;
	hanoi[2][B] = 11;
	hanoi[2][BB] = 6;

	hanoi[3][R] = 13;
	hanoi[3][B] = 27;
	hanoi[3][BB] = 14;


	for (ll i = 3; i <= n; i++) {
		hanoi[i][R] = (1 + 2 * hanoi[i - 1][BB]) % MOD;
		hanoi[i][B] = (1 + 2 * hanoi[i][R]) % MOD;
		hanoi[i][BB] = (2 * hanoi[i - 1][BB] + 2) % MOD;
	}
	cout << hanoi[n][B] << endl;
	return 0;
}