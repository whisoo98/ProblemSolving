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
#define N 510
#define ll long long
#define endl "\n"
#define MID(a,b) (a+b)/2

using namespace std;

int arr[N][N];
int y, x;
int dy[] = { 0,1,2 };
int dx[] = { 0,1,2 };
int m = -1;

void Sum(int ty, int tx,int flag) {
	int sum = 0;
	int temp;
	if (flag) { //세로 3칸
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 2; j++) {
				sum += arr[ty + i][tx + j];
			}
		}
		temp = sum;
		temp -= (arr[ty + dy[0]][tx + dx[0]] + arr[ty + dy[0]][tx + dx[1]]);
		m = max(temp, m);

		temp = sum;
		temp -= (arr[ty + dy[0]][tx + dx[0]] + arr[ty + dy[1]][tx + dx[0]]);
		m = max(temp, m);
		
		temp = sum;
		temp -= (arr[ty + dy[0]][tx + dx[0]] + arr[ty + dy[2]][tx + dx[0]]);
		m = max(temp, m);
		
		temp = sum;
		temp -= (arr[ty + dy[0]][tx + dx[0]] + arr[ty + dy[2]][tx + dx[1]]);
		m = max(temp, m);

		
		temp = sum;
		temp -= (arr[ty + dy[0]][tx + dx[1]] + arr[ty + dy[1]][tx + dx[1]]);
		m = max(temp, m);

		temp = sum;
		temp -= (arr[ty + dy[0]][tx + dx[1]] + arr[ty + dy[2]][tx + dx[0]]);
		m = max(temp, m);

		temp = sum;
		temp -= (arr[ty + dy[0]][tx + dx[1]] + arr[ty + dy[2]][tx + dx[1]]);
		m = max(temp, m);

		temp = sum;
		temp -= (arr[ty + dy[1]][tx + dx[0]] + arr[ty + dy[2]][tx + dx[0]]);
		m = max(temp, m);

		temp = sum;
		temp -= (arr[ty + dy[1]][tx + dx[1]] + arr[ty + dy[2]][tx + dx[1]]);
		m = max(temp, m);

		temp = sum;
		temp -= (arr[ty + dy[2]][tx + dx[0]] + arr[ty + dy[2]][tx + dx[1]]);
		m = max(temp, m);
	}
	else {//가로 3칸
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 3; j++) {
				sum += arr[ty + i][tx + j];
			}
		}
		temp = sum;
		temp -= (arr[ty + dy[0]][tx + dx[0]] + arr[ty + dy[0]][tx + dx[1]]);
		m = max(temp, m);

		temp = sum;
		temp -= (arr[ty + dy[0]][tx + dx[0]] + arr[ty + dy[1]][tx + dx[0]]);
		m = max(temp, m);

		temp = sum;
		temp -= (arr[ty + dy[0]][tx + dx[0]] + arr[ty + dy[0]][tx + dx[2]]);
		m = max(temp, m);

		temp = sum;
		temp -= (arr[ty + dy[0]][tx + dx[0]] + arr[ty + dy[1]][tx + dx[2]]);
		m = max(temp, m);


		temp = sum;
		temp -= (arr[ty + dy[1]][tx + dx[0]] + arr[ty + dy[1]][tx + dx[1]]);
		m = max(temp, m);

		temp = sum;
		temp -= (arr[ty + dy[1]][tx + dx[0]] + arr[ty + dy[0]][tx + dx[2]]);
		m = max(temp, m);

		temp = sum;
		temp -= (arr[ty + dy[1]][tx + dx[0]] + arr[ty + dy[1]][tx + dx[2]]);
		m = max(temp, m);

		temp = sum;
		temp -= (arr[ty + dy[0]][tx + dx[1]] + arr[ty + dy[0]][tx + dx[2]]);
		m = max(temp, m);

		temp = sum;
		temp -= (arr[ty + dy[1]][tx + dx[1]] + arr[ty + dy[1]][tx + dx[2]]);
		m = max(temp, m);

		temp = sum;
		temp -= (arr[ty + dy[0]][tx + dx[2]] + arr[ty + dy[1]][tx + dx[2]]);
		m = max(temp, m);
	}
//	return temp;
}
void query(int ty, int tx) {
	int temp = 0;
	{
		for (int i = 0; i < 4; i++) {
			temp += arr[ty + i][tx];
		}
		m = max(temp, m);
		
	}
	{
		//temp = 0;
		Sum(ty, tx, 1);
	}
	{
		Sum(ty, tx, 0);

	}
	{
		temp = 0;
		for (int i = 0; i < 4; i++) {
			temp += arr[ty][tx + i];
		}
		m = max(temp, m);

	}
}

int main()
{	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, j; //for문 변수 -> longlong필요한지 확인
	cin >> y >> x;
	for (i = 1; i <= y; i++) {
		for (j = 1; j <= x; j++) {
			cin >> arr[i][j];
		}
	}
	for (i = 1; i <= y; i++) {
		for (j = 1; j <= x; j++) {
			query(i, j);
		}
	}
	cout << m;
	return 0;
}