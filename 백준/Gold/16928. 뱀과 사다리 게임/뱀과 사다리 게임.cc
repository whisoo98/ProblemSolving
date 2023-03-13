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

int ladderstart[20];
int ladderend[20];

int snakestart[20];
int snakeend[20];
int dp[105];
void Solution(int n,int m) {
	queue<int> pos;
	for (int i = 0; i <= 100; i++) dp[i] = 987654321;
	dp[1] = 0;
	pos.push(1);
	while (pos.size()) {
		int now = pos.front(); pos.pop();
		int snaked = 0;
		for (int i = 0; i < m; i++) {
			if (snakestart[i] == now) {
				dp[snakeend[i]] = min(dp[now], dp[snakeend[i]]);
				now = snakeend[i];
				snaked = 1;
				break;

				//now = ladderend[i];
				//snaked = 1;
				//break;
			}
		}
		if (!snaked) {

			for (int i = 0; i < n; i++) {
				if (ladderstart[i] == now) {
					dp[ladderend[i]] = min(dp[now], dp[ladderend[i]]);
					now = ladderend[i];
					break;
				}
			}
		}
		for (int i = now + 1; i <= now + 6; i++) {
			if (i<=100 && dp[i] > dp[now] + 1) {
				dp[i] = dp[now] + 1;
				pos.push(i);
			}
		}
	}
	

}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, j; //for문 변수 -> longlong필요한지 확인
	int n, m; cin >> n >> m;
	//cin >> ladder >> snake;
	for (int i = 0; i < n; i++) cin >> ladderstart[i]>>ladderend[i];
	for (int i = 0; i < m; i++) cin >> snakestart[i] >> snakeend[i];
	Solution(n, m);
	cout << dp[100];
	return 0;
}