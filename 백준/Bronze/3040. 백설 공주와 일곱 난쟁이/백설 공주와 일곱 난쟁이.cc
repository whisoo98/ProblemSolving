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
#define N 10
#define ll long long
#define endl "\n"
#define MID(a,b) (a+b)/2

using namespace std;


vector<int> comb = { 0,0,1,1,1,1,1,1,1 };
int arr[N];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, j; //for문 변수 -> longlong필요한지 확인
	int n = 9;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	do {
		int sum = 0;
		for (int i = 0; i < n; i++) {
			if (comb[i]) {
				sum += arr[i];
			}
		}
		if (sum == 100) break;
	} while (next_permutation(comb.begin(), comb.end()));
	for (int i = 0; i < n; i++) {
		if (comb[i]) {
			cout << arr[i] << endl;
		}
	}
	return 0;
}