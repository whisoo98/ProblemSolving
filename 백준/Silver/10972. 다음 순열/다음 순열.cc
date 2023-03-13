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
#define N 10'005
#define ll long long
#define endl "\n"
#define MID(a,b) (a+b)/2

using namespace std;

int arr[N];


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, j; //for문 변수 -> longlong필요한지 확인
	int n; cin >> n;
	
	for (i = 0; i < n; i++) cin >> arr[i];
	if (next_permutation(arr, arr + n)) {
		for (i = 0; i < n; i++) cout<< arr[i]<< " ";

	}
	else cout << -1;
	return 0;
}