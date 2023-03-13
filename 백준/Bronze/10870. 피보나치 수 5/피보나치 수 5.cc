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

//int arr[N];//int인데 출력하고자 하는 값이 int범위보다 크다!
ll arr[N];



int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, j; //for문 변수 -> longlong필요한지 확인
	int n; scanf("%d", &n);
	arr[0] = 0;
	arr[1] = 1;
	for (i = 2; i <= n; i++) {
		arr[i] = arr[i - 1] + arr[i - 2];
		//arr[i] => Fi
	}
	printf("%lld", arr[n]);
	return 0;
}