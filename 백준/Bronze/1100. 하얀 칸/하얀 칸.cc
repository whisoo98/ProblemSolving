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
#define N 10
#define ll long long
#define endl "\n"
#define MID(a,b) (a+b)/2

using namespace std;

char arr[N][N];
int board[N][N] = {
	{1,0,1,0,1,0,1,0,},
	{0,1,0,1,0,1,0,1,},
	{1,0,1,0,1,0,1,0,},
	{0,1,0,1,0,1,0,1,},
	{1,0,1,0,1,0,1,0,},
	{0,1,0,1,0,1,0,1,},
	{1,0,1,0,1,0,1,0,},
	{0,1,0,1,0,1,0,1,},
};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, j; //for문 변수 -> longlong필요한지 확인
	for (i = 0; i < 8; i++) {
		for (j = 0; j < 8; j++) {
			cin >> arr[i][j];
		}
	}
	int answer = 0;
	for (i = 0; i < 8; i++) {
		for (j = 0; j < 8; j++) {
			if (board[i][j] == 1) {
				if (arr[i][j] == 'F') {
					answer++;
				}
			}
		}
	}
	cout << answer;
	
	
	return 0;
}