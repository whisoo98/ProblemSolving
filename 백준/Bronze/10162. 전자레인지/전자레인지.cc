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

int min5 = 300;
int min1 = 60;
int min0 = 10;
int arr[5];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, j; //for문 변수 -> longlong필요한지 확인
	int T; cin >> T;
	arr[1] = T / min5;
	T %= min5;
	arr[2] = T / min1;
	T %= min1;
	arr[3] = T / min0;
	T %= min0;
	if (T) {
		cout << -1;
	}
	else {
		for (i = 1; i <= 3; i++) {
			cout << arr[i] << " ";
		}
	}
	return 0;
}