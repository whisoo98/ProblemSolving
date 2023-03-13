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

using namespace std;

string s;
int Find(int left, int right) {
	if (left >= right) return 1;
	if (s[left] == s[right]) return Find(left + 1, right - 1);
	else return 0;
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, j; //for문 변수 -> longlong필요한지 확인
	while (1) {
		cin >> s;
		if (s == "0") break;
		if (Find(0, s.length() - 1)) {
			cout << "yes\n";
		}
		else cout << "no\n";
	}

	return 0;
}