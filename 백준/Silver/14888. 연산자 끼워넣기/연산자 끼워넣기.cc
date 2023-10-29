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
#define N 15
#define ll long long
#define endl "\n"
#define MID(a,b) (a+b)/2
#define PLUS 0
#define MINUS 1
#define MUL 2
#define DIV 3
#define MAX 0
#define MIN 1
using namespace std;

ll numbers[N];
int ops[N];
int n;
ll ans_max = INT_MIN;
ll ans_min = INT_MAX;

void calcExp(int idx, ll result) {
	if (idx == n - 1) {
		ans_max = max(ans_max, result);
		ans_min = min(ans_min, result);
		return;
	}
	for (int i = 0; i < 4; i++) {
		if (ops[i]) {
			ops[i]--;
			if (i == PLUS) {
				calcExp(idx + 1, result + numbers[idx + 1]);
			}
			else if (i == MINUS) {
				calcExp(idx + 1, result - numbers[idx + 1]);
			}
			else if (i == MUL) {
				calcExp(idx + 1, result * numbers[idx + 1]);
			}
			else if (i == DIV) {
				calcExp(idx + 1, result / numbers[idx + 1]);
			}
			ops[i]++;
		}
	}

}

void Solution(int n) {
	calcExp(0, numbers[0]);
	cout << ans_max << endl;
	cout << ans_min << endl;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, j; //for문 변수 -> longlong필요한지 확인
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> numbers[i];
	}
	for (int i = 0; i < 4; i++) {
		cin >> ops[i];
	}
	Solution(n);
	return 0;
}