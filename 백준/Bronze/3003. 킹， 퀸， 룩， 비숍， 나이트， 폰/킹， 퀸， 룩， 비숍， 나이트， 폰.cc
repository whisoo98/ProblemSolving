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

using namespace std;
int arr[10];



int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, j; //for문 변수 -> longlong필요한지 확인
	
	for (i = 1; i <= 6; i++) {
		cin >> arr[i];
	}
	printf("%d ", 1 - arr[1]);
	printf("%d ", 1 - arr[2]);
	printf("%d ", 2 - arr[3]);
	printf("%d ", 2 - arr[4]);
	printf("%d ", 2 - arr[5]);
	printf("%d ", 8 - arr[6]);
	return 0;
}