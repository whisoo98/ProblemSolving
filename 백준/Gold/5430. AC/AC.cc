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
#define N 100005
#define ll long long
#define endl "\n"
#define MID(a,b) (a+b)/2

using namespace std;

//deque<int> v;



int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, j; //for문 변수 -> longlong필요한지 확인
	int T; cin >> T;
	while (T--) {
		deque<int> v;
		string cmd; cin >> cmd;
		int n; cin >> n;
		string s; cin >> s;
		stringstream ss;
		ss << s;
		char del;
		ss >> del;
		while (v.size()<n) {
			int a; ss >> a; v.push_back(a);
			ss >> del;
		}
		
		int toggle = 1;
		int len = cmd.length();
		int chk = 0;
		for (i = 0; i < len; i++) {
			if (cmd[i] == 'R') {
				toggle *= -1;
			}
			else {
				if (v.empty()) {
					chk++;
					break;
				}
				if (toggle == 1) {
					v.pop_front();
				}
				else {
					v.pop_back();
				}
			}
		}
		if (chk) {
			cout << "error" << endl;
		}
		else {
			if (v.empty()) {
				cout << "[]\n";
			}
			else {
				cout << "[";
				while (v.size() > 1) {
					if (toggle == 1) {
						int a; a = v.front();
						v.pop_front();
						cout << a << ",";
					}
					else {
						int a; a = v.back();
						v.pop_back();
						cout << a << ",";
					}
				}
				cout << v.back();
				cout << "]" << endl;
			}
		}
		//cout << endl;
	}
	return 0;
}