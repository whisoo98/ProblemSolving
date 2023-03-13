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
	
	vector<int> v;
	
	for (i = 0; i <= 9999; i++) {
		v.push_back(i * 1000 + 666);
	}
	for (i = 0; i <= 999; i++) {
		for (j = 0; j < 10; j++) {
			v.push_back(i * 10000 + 6660 + j);
		}
	}
	for (i = 0; i <= 99; i++) {
		for (j = 0; j < 100; j++) {
			v.push_back(i * 100000 + 66600 + j);
		}
	}
	for (i = 0; i <= 9; i++) {
		for (j = 0; j < 1000; j++) {
			v.push_back(i * 1000000 + 666000 + j);
		}
	}
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());
	
	
	cout << v[n - 1];
	return 0;
}