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

deque<pair<int,int>> dq;


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, j; //for문 변수 -> longlong필요한지 확인
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		int a; cin >> a;
		dq.push_back({ i + 1,a });
	}
	int a;
	int flag = 1;
	int b;
	while (dq.size()) {
		if (flag < 0) {
			a = dq.back().second;
			b = dq.back().first;
			dq.pop_back();
		}
		else {
			a = dq.front().second;
			b = dq.front().first;
			dq.pop_front();
		}
		cout << b << " ";
		flag = a;
		if (!dq.size()) break;
		if (a < 0) {
				a++;
			while (a!=0) {
				a++;

				int c = dq.back().second;
				int d = dq.back().first;
				dq.pop_back();

				dq.push_front({ d,c });
			}
		}
		else {
				a--;
			while (a!=0) {
				a--;

				int c = dq.front().second;
				int d = dq.front().first;
				dq.pop_front();

				dq.push_back({ d,c });
			}
		}
	}
	cout << endl;
	return 0;
}