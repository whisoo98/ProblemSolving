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

int arr[15] = { 4,2,3,3,3,3,3,3,3,3, };


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, j; //for문 변수 -> longlong필요한지 확인
	while (1) {
		int a; cin >> a;
		int tot = 1;
		if (a == 0)break;
		while (a) {
			int temp = a % 10;
			a /= 10;
			tot += arr[temp]+1;
		}
		cout << tot << endl;
	}

	return 0;
}