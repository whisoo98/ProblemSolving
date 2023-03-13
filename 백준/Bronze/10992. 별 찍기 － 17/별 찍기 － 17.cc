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
	int n; scanf("%d", &n);
	for (i = 1; i <= n; i++) {
		for (j = i; j < n; j++) {
			printf(" ");
		}
		if (i == 1) {
			printf("*");
		}
		else if (i == n) {
			for (j = 1; j <= 2 * n - 1; j++) {
				printf("*");
			}
		}
		else {
			printf("*");
			for (j = 1; j <= 2 * (i - 2) + 1; j++) {
				printf(" ");
			}
			printf("*");
		}
		printf("\n");
	}
	return 0;
}