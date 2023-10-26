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


int cutStick(string s) {
	int stick_count = 0;
	int num_cut_stick = 0;
	int before_open = 0;
	int sz = s.size();
	for (int i = 0; i < sz; i++) {
		if (s[i] == '(') {
			stick_count++;
			before_open = true;
		}
		else {
			stick_count--;
			if (before_open) {
				num_cut_stick += stick_count;
			}
			else {
				num_cut_stick++;
			}
			before_open = false;
		}
	}
	return num_cut_stick;
}

void Solution(string s) {
	int ans = cutStick(s);
	cout << ans << endl;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, j; //for문 변수 -> longlong필요한지 확인
	string s; cin >> s;
	Solution(s);
	return 0;
}