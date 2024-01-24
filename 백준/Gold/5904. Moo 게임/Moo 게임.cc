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



int krr[N];

int findK(int n) {
	int k = 0;
	int len_k = 3;
	krr[0] = len_k;
	while (len_k < n) {
		k++;
		len_k = len_k + 1 + k + 2 + len_k;
		krr[k] = len_k;
	}
	return k;
}

int DNC(int n, int k) {
	if (k == 0) {
		if (n == 1) {
			return 'm';
		}
		else {
			return 'o';
		}
	}
	if (n) {
		int len_k = krr[k];
		int len_k_1 = krr[k - 1];
		if (n <= len_k_1) {
			return DNC(n, k - 1);
		}
		else if (n <= len_k_1 + 1) {
			return 'm';
		}
		else if (n <= len_k_1 + 1 + (k - 1 + 2) + 1) {
			return 'o';
		}
		else {
			return DNC(n - (len_k_1 + 1 + (k - 1 + 2) + 1), k - 1);
		}
	}
	else {
		return 0;
	}
}


void Solution(int n) {
	int k = findK(n); // k -> S(k) s.t. convers n.
	char ans = DNC(n, k);
	cout << ans << endl;
	//cout << ans << " ";
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, j; //for문 변수 -> longlong필요한지 확인
	//while (1) {
		int n; cin >> n;
		Solution(n);
	//}
	return 0;
}