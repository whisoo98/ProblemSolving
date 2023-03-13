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
#define N 205

using namespace std;

int dp[N][N];


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, j; //for문 변수 -> longlong필요한지 확인
	
	while (1) {
		string s1; cin >> s1;
		if (cin.eof()) break;
		string s2; cin >> s2;
		
		
		int len1 = s1.length();
		int len2 = s2.length();
		for (i = 1; i <= len1; i++) {
			for (j = 1; j <= len2; j++) {
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
				if (s1[i - 1] == s2[j - 1]) {
					dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 1);
				}
			}
		}
		cout << dp[len1][len2]<<"\n";

		for (i = 1; i <= len1; i++) {
			for (j = 1; j <= len2; j++) {
				dp[i][j] = 0;
			}
		}
		
	}
	return 0;
}