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

string sixteen = "0123456789ABCDEF";


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, j; //for문 변수 -> longlong필요한지 확인
	string s;
	cin >> s;
	int len = s.length();
	int len2 = sixteen.length();
	int sum = 0;
	int cnt = 0;
	for (i = len - 1; i >= 0; i--) {
		for (j = 0; j < len2; j++) {
			if (s[i] == sixteen[j]) {
				sum += pow(16, cnt)*j;
			}
		}
		cnt++;
	}
	cout << sum;
	return 0;
}