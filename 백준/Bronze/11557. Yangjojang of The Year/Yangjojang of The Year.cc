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

	int T; cin >> T;
	while (T--) {
		int n; cin >> n;
		string s; int m=-1;
		for (int i = 0; i < n; i++) {
			string tmp; 
			int temp;
			cin >> tmp >> temp;
			if (m < temp) {
				m = temp;
				s=  tmp;
			}

		}
		cout << s << endl;
	}

	return 0;
}