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




int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, j; //for문 변수 -> longlong필요한지 확인
	int a, b, c; cin >> a >> b >> c;
	int A, B, C; cin >> A >> B >> C;
	int del[5];
	del[1] = A - a;
	del[2] = B - b;
	del[3] = C - c;
	if (del[1] == 0) {
		if (del[2] < 0) {
			if (del[3] < 0) {

			}
			else if (del[3] == 0) {

			}
			else {

			}
		}
		else if (del[2] == 0) {
			if (del[3] < 0) {

			}
			else if (del[3] == 0) {
				cout << 0 << endl << 1 << endl << 0;
			}
			else {
				cout << 0 << endl << 1 << endl << 0;
			}
		}
		else {
			if (del[3] < 0) {
				cout << 0 << endl << 1 << endl << 0;
			}
			else if (del[3] == 0) {
				cout << 0 << endl << 1 << endl << 0;
			}
			else {
				cout << 0 << endl << 1 << endl << 0;
			}
		}
	}
	else {
		if (del[2] < 0) {
			if (del[3] < 0) {
				cout << del[1]-1 << endl << del[1]+1 << endl << del[1];
			}
			else if (del[3] == 0) {
				cout << del[1] - 1 << endl << del[1] + 1 << endl << del[1];
			}
			else {
				cout << del[1] - 1 << endl << del[1] + 1 << endl << del[1];
			}
		}
		else if (del[2] == 0) {
			if (del[3] < 0) {
				cout << del[1] - 1 << endl << del[1] + 1 << endl << del[1];
			}
			else if (del[3] == 0) {
				cout << del[1] << endl << del[1]+1 << endl << del[1];
			}
			else {
				cout << del[1] << endl << del[1] + 1 << endl << del[1];

			}
		}
		else {
			if (del[3] < 0) {
				cout << del[1] << endl << del[1] + 1 << endl << del[1];

			}
			else if (del[3] == 0) {
				cout << del[1] << endl << del[1] + 1 << endl << del[1];

			}
			else {
				cout << del[1] << endl << del[1] + 1 << endl << del[1];

			}
		}
	}
	return 0;
}