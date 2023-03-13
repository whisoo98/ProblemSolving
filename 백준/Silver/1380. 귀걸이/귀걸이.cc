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
#define N 105
#define ll long long
#define endl "\n"
#define MID(a,b) (a+b)/2

using namespace std;


//vector<string> name;
map<int, string> name;
int arr[N];
int main()
{

	int i, j; //for문 변수 -> longlong필요한지 확인
	int T = 1;
	while (1) {
		int n; scanf("%d", &n);
		if (n == 0) break;
		getchar();
		for (ll i = 0; i < n; i++) {
			string s;
			getline(cin, s);
			name[i + 1] = s;
		}
		for (i = 0; i < n * 2 - 1; i++) {
			int a; char b; cin >> a >> b;
			arr[a] = !arr[a];
		}
		for (ll i = 0; i < n; i++) {
			if (arr[i + 1]) {
				//cout << T << " " << name[i + 1] << endl;
				printf("%d %s\n", T, name[i + 1].c_str());
				arr[i + 1] = 0;
			}
		}
		name.clear();
		T++;
	}
	return 0;
}