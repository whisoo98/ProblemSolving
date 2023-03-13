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
	int arr[5];
	for (i = 1; i <= 4; i++) {
		cin >> arr[i];
	}
	sort(arr + 1, arr + 1 + 4);
	int t1 = arr[4] + arr[1], t2 = arr[3] + arr[2];
	cout << abs(t1 - t2);
	return 0;
}