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
#define N 1000005
using namespace std;

int arr[N * 2]; 


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, j; //for문 변수 -> longlong필요한지 확인
	int n; cin >> n;
	for (i = 1; i < N * 2; i++) {
		arr[i] = 987654321;
	}

	for (i = 1; i <= n; i++) {
		int temp = i;
		int sum = temp;
		while (temp) {
			sum += temp % 10;
			temp /= 10;
		}
		arr[sum] = min(arr[sum], i);
	}
	if (arr[n] == 987654321) {
		cout << 0;
	}
	else cout << arr[n];
	
	return 0;
}