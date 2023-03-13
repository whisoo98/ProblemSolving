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
#define N 10005
#define ll long long
#define endl "\n"
#define MID(a,b) (a+b)/2

using namespace std;

int prime[N];
void era(int num) {
	for (int i = 2; i <= num; i++) prime[i] = 1;
	for (int i = 2; i <= sqrt(num); i++) {
		if (prime[i] == 0) // 이미 체크된 수의 배수는 확인하지 않는다
			continue;
		for (int j = i * i; j <= num; j += i) { // i를 제외한 i의 배수들은 0으로 체크
			prime[j] = 0;
		}

	}
}



int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, j; //for문 변수 -> longlong필요한지 확인
	int n, m; cin >> n >> m;
	era(10000);
	int M = 987654321;
	int sum = 0;
	for (i = n; i <= m; i++) {
		if (prime[i] == 1) {
			M = min(M, i);
			sum += i;
		}
	}
	if (M == 987654321) {
		cout << -1;
	}
	else cout << sum << endl << M;
	return 0;
}