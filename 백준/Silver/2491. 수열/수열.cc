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

vector<int> arr;
int Descending[N];
int Ascending[N];
void Solution(int n) {
	int sz = arr.size();
	Descending[0] = 1;
	Ascending[0] = 1;
	for (int i = 1; i < sz; i++) {
		//for Ascending
		if (arr[i] >= arr[i - 1]) {
			Ascending[i] = Ascending[i - 1] + 1;
		}
		else {
			Ascending[i] = 1;
		}

		//for Descending
		if (arr[i] <= arr[i - 1]) {
			Descending[i] = Descending[i - 1] + 1;
		}
		else {
			Descending[i] = 1;
		}
	}
	cout << max(*max_element(Ascending, Ascending + n), *max_element(Descending, Descending + n)) << endl;
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, j; //for문 변수 -> longlong필요한지 확인
	//int T = 3;
	//while (T--) {
		int n; cin >> n;
		for (int i = 1; i <= n; i++) {
			int a; cin >> a;
			arr.push_back(a);
		}
		Solution(n);
		arr.clear();
	//}
	return 0;
}