#include <iostream>
#include <algorithm>
#include <functional>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <string>
#include <queue>
#include <stack>
#include <map>
#include <vector>
#include <set>
#include <sstream>

using namespace std;

int arr[105];


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, j; //for문 변수 -> longlong필요한지 확인
	int n, m; cin >> n >> m;
	for (i = 0; i < n; i++) {
		cin >> arr[i];
	}
	int sum = -1;
	sort(arr, arr + n);
	for (i = 0; i < n; i++) {
		for (j = i + 1; j < n; j++) {
			for (int k = j + 1; k < n; k++) {
				int temp = arr[i] + arr[j] + arr[k];
				if (temp <= m) sum = max(sum, temp);
			}
		}
	}
	cout << sum;
	return 0;
}