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




int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, j; //for문 변수 -> longlong필요한지 확인
	int arr[5];
	while (1) {
		cin >> arr[1] >> arr[2] >> arr[3];
		if (arr[1] * arr[2] * arr[3] == 0) return 0;
		sort(arr + 1, arr + 4, greater<int>());
		if (arr[1] * arr[1] == arr[2] * arr[2] + arr[3] * arr[3]) cout << "right\n";
		else cout << "wrong\n";
	}

	return 0;
}