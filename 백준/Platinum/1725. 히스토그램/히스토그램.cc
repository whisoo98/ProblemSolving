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
#define N 100'005
#define ll long long
#define endl "\n"
#define MID(a,b) (a+b)/2

using namespace std;

int arr[N];


void monotoneStack(int n) {
	stack<int> stk_height;
	stack<int> stk_cnt;
	stk_height.push(0);
	stk_cnt.push(0);
	int  M = 0;

	for (int i = 0; i < n + 1; i++) {
		int height = arr[i];
		int add = 0;
		while (1) {
			int cmp_height = stk_height.top();
			int cmp_cnt = stk_cnt.top();
			int mul_cnt = cmp_cnt + add;

			if (height < cmp_height) {
				stk_height.pop();
				stk_cnt.pop();
				M = max(M, cmp_height*mul_cnt);
				add += cmp_cnt;
			}
			else if (height >= cmp_height) {
				stk_height.push(height);
				stk_cnt.push(1 + add);
				break;
			}
		}
	}
	cout << M << endl;
}

void Solution(int n) {
	monotoneStack(n);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, j; //for문 변수 -> longlong필요한지 확인
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	Solution(n);
	return 0;
}