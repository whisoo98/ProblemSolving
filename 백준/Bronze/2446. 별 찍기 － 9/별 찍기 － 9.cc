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
	for (i = 1; i <= n; i++) {
		
			for (j = 1; j < i; j++) {
				cout << " ";
			}
			for (j = i; j <= 2*n-i; j++) {
				cout << "*";
			}
			cout << endl;
	}
	for (i = n-1; i >= 1; i--) {
		for (j = 1; j < i; j++) {
			cout << " ";
		}
		for (j = i; j <= 2 * n - i; j++) {
			cout << "*";
		}
		cout << endl;
	}
	return 0;
}