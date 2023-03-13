#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <functional>
#include <stdlib.h>
#include <string>
#include <queue>
#include <stack>
#include <map>
#include <climits>
#include <cstring>


using namespace std;

/*struct type_name {

}srt;*/

//vector <type> vec;
//stack <type> stk;
//queue <type> q;
//string str;
//map <key_type,value_type> m;
int arr[25][305];
int dp[25][305];
int track[25][305];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int i, j;//for문변수-->가끔식 long으로
	
	int n, m; cin >> n >> m; // n 투자금액 m 기업의 수
	for (i = 1; i <= n; i++) {
		int temp; cin >> temp;
		for (j = 1; j <= m; j++) {
			cin >> arr[j][i];
		}
	}
	for (int k = 1; k <= m; k++) { //k번째 기업
		for (i = 0; i <= n; i++) { //총 i만원 투자
			int M = 0;
			int corp = 0;
			for (j = 0; j <= i; j++) {//k번째 기업이 j만원 투자 나머지 기업에 i-j원 투자
				if (arr[k][j] + dp[k - 1][i - j] > M) {
					M = arr[k][j] + dp[k - 1][i - j];
					corp = j;
				}
				else dp[k][i] = max(dp[k][i], dp[k-1][i]);
			}
			dp[k][i] = M;
			track[k][i] = corp;
		}
	}
	int idx = max_element(dp[m], dp[m] + n + 1) - dp[m];
	cout << dp[m][idx] << "\n";
	/*for (i = 1; i <= m; i++) {
		for (j = 0; j <= n; j++) {
			cout << dp[i][j] << " ";
		}
		cout << endl;
	}
	for (i = 1; i <= m; i++) {
		for (j = 0; j <= n; j++) {
			cout << track[i][j] << " ";
		}
		cout << endl;
	}*/
	stack<int> stk;
	int sum = 0;
	for (i = m; i > 0; i--) {
		idx = max_element(dp[i], dp[i] + n+1-sum) - dp[i];
		stk.push(track[i][idx]);
		sum += track[i][idx];
		//cout << track[i][idx] << " ";
	}
	while (!stk.empty()) {
		cout <<stk.top() << " ";
		stk.pop();
	}
	return 0;
}