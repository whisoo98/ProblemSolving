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
#include<cmath>
#define N 1000000009

using namespace std;

/*struct type_name {

}srt;*/

//vector <type> vec;
//stack <type> stk;
//queue <type> q;
//string str;
//map <key_type,value_type> m;
long long dp[1000005];
int n, k;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int i, j;//for문변수-->가끔식 long으로
	cin >> n >> k;
	dp[0] = 1;
	dp[1] = k;
	dp[2] = k * k;
	dp[3] = k * k * k;
	dp[4] = k * k * k * k;
	int ERR = 2;
	for (i = 5; i <= n; i++) {
		if (i < 7)
			dp[i]=(dp[i - 1] * k - dp[i - 5] * 2) % N;
		if (i >= 7)
			dp[i] = (dp[i - 1] * k - dp[i - 5] * 2 + dp[i - 7]) % N;
		if (dp[i] < 0) dp[i] += N;
	}
	//ABCBC ABABC
	
	//ABABCBC
	cout << dp[n] << endl; //->사이 구간에 잇으면 즉 x~y에 오류코드가 있으면 그부분 외으ㅔ 부분에 대해서 경우의수 구해서 뺴주자


	return 0;
}