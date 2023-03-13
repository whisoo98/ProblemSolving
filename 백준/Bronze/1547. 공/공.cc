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



int arr[5];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, j; //for문 변수 -> longlong필요한지 확인
	int n; cin >> n;
	arr[1] = 1;
	for (i = 1; i <= n; i++) {
		int a, b; cin >> a >> b;
		if (arr[a]) {
			arr[a] = 0;
			arr[b] = 1;
		}
		else if (arr[b]) {
			arr[b] = 0;
			arr[a] = 1;
		}
	}
	for (i = 1; i <= 3; i++) {
		if (arr[i])cout << i;
	}
	return 0;
}