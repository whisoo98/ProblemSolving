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
#include <cmath>
#include <sstream>


using namespace std;

/*struct type_name {

}srt;*/

//vector <type> vec;
//stack <type> stk;
//queue <type> q;
//string str;
//map <key_type,value_type> m;
int y, x, n;
int arr[105][105][2];//0은 오른쪽 1은 위쪽
long long dp[105][105];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int i, j;//for문변수-->가끔식 long으로
	cin >> x >> y;
	cin >> n;
	for (i = 0; i < n; i++) {
		int a, b, c, d; cin >> a >> b >> c >> d;
		if (a == c) {//x자ㅗ표 동일 ->아래에서 위로 올수 없음 ->1에표시
			arr[max(b, d)][a][1] = 1;
		}
		else if (d == b) {//y좌표동일 -> 왼쪽에서 오른쪽으로 올 수 없음 ->0에표시
			arr[b][max(a, c)][0] = 1;
		}
	}
	dp[0][0] = 1;
	for (i = 0; i <= y; i++) {
		for (j = 0; j <= x; j++) {
			if (i == 0 && j == 0) continue;
			if (i == 0 && j != 0) { //y좌표가 0 -> 맨 아랫줄
				if (arr[i][j][0] == 1) {//왼쪽을 더할수 없음
					dp[i][j] = 0;
				}
				else {
					dp[i][j] += dp[i][j - 1];
				}
			}
			if (j == 0 && i != 0) {//x좌표가 0 -> 맨 왼쪽줄
				if (arr[i][j][1] == 1) {//아래쪽을 더할수 없음
					dp[i][j] = 0;
				}
				else {
					dp[i][j] += dp[i - 1][j];
				}
			}
			else if (j != 0 && i != 0) {
				dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
				if (arr[i][j][0] == 1) {
					dp[i][j] -= dp[i][j - 1];
				}
				if (arr[i][j][1] == 1) {
					dp[i][j] -= dp[i - 1][j];
				}
			}
		}
	}
	cout << dp[y][x];
	//for(i=0;i<n;i++) {}
	//for(i=0;i<n;i++) { for(j=0;j<n;j++) { } }

	return 0;
}