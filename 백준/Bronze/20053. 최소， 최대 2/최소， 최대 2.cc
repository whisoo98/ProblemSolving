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

using namespace std;


int arr[N];

void Solution(int n) {
	int M = *max_element(arr, arr + n);
	int m = *min_element(arr, arr + n);
	cout << m << " " << M << endl;
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, j; //for문 변수 -> longlong필요한지 확인
	int T;
	cin >> T;
	while (T--) {
		memset(arr, 0, sizeof(arr));
		int n; cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
		}
		Solution(n);
	}

	return 0;
}