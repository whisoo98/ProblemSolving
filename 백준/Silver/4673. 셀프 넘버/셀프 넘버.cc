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
#define N 10000
#define ll long long
#define endl "\n"
#define MID(a,b) (a+b)/2

using namespace std;

int arr[4*N];
void Karpreka(int a,int target) {
	if (a > N) {
		return;
	}
	int sum = 0;
	int temp = a;
	while (temp) {
		sum += temp % 10;
		temp /= 10;
	}
	a += sum;
	arr[a] = 1;
	if (a == target) return;
	Karpreka(a,target);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, j; //for문 변수 -> longlong필요한지 확인
	
	for (i = 1; i <= N; i++) {
		Karpreka(i,i);
	}
	for (i = 1; i <= N; i++) {
		if (arr[i] == 0) cout << i << endl;
	}
	return 0;
}