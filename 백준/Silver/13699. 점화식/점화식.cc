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
#define N 100
#define ll long long
#define endl "\n"
#define MID(a,b) (a+b)/2

using namespace std;

ll arr[N];
//int 범위보다 답의 크기가 더 크기때문에 답이 정확히 나오지 않는다.


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, j; //for문 변수 -> longlong필요한지 확인
	//int n; cin >> n;
	int n; scanf("%d", &n);
	arr[0] = 1;
	for (i = 1; i <= n; i++) {
		for (j = 0; j < i; j++) {
			arr[i] += arr[j] * arr[i - 1 - j];
		}
	}
	printf("%lld", arr[n]);
	return 0;
}