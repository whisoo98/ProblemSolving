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
	int n; cin >> n;
	if (n == 1) {
		cout << "1/1";
		return 0;
	}
	int temp;

	for (i = 1; i <= 10000; i++) {
		if (n <= i * (i+1) / 2) {
			j = i;
			//temp = n - (i - 1)*(i) / 2;
			break;
		}
	}
	//cout << j << endl;
	if (j % 2) {//왼쪽 시작 -> 분모 시작 1
		temp = n - (j - 1)*(j) / 2;

		j++;
		cout << j - temp << "/" << temp;
	}
	else {//오른쪽 시작 -> 분자 시작 1
		temp = n - (j - 1)*(j) / 2;

		j++;
		cout << temp << "/" << j - temp;

	}
	return 0;
}