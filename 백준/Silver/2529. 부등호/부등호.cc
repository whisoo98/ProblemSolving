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

string numbers = "0123456789";
string Mans, mans;
int visit[10];

ll cmp;
int flag;
void dfs(int n, int start, int diff, int idx, vector<char> buho, vector<int> v) {
	if (flag == 1) return;
	if (n == idx) {
		if (diff == 1) { // ascending
			ll temp = 0;
			string stemp = "";
			for (auto it : v) {
				temp *= 10;
				temp += it;
				stemp += numbers[it];
			}
			if (cmp > temp) {
				cmp = temp;
				mans = stemp;
				flag = 1;
			}
		}
		else { // descending
			ll temp = 0;
			string stemp = "";
			for (auto it : v) {
				temp *= 10;
				temp += it;
				stemp += numbers[it];
			}
			if (cmp < temp) {
				cmp = temp;
				Mans = stemp;
				flag = 1;
			}
		}
		return;
	}
	if (v.size() == 0) {
		for (int i = start; i <= 9 && i >= 0; i += diff) {
			visit[i] = 1;
			v.push_back(i);
			dfs(n, start, diff, idx, buho, v);
			v.pop_back();
			visit[i] = 0;
		}
	}
	else {
		for (int i = start; i <= 9 && i >= 0; i += diff) {

			if (!visit[i]) {
				visit[i] = 1;
				if (buho[idx] == '<') {
					if (v[idx] < i) {
						v.push_back(i);
						dfs(n, start, diff, idx + 1, buho, v);
						v.pop_back();
						visit[i] = 0;

					}
					else {
						visit[i] = 0;
						continue;
					}
				}
				else {
					if (v[idx] > i) {
						v.push_back(i);
						dfs(n, start, diff, idx + 1, buho, v);
						v.pop_back();

						visit[i] = 0;

					}
					else {
						visit[i] = 0;
						continue;
					}
				}
			}
		}
	}
}
void Solution(int n, vector<char> buho) {

	vector<int> v;
	cmp = LLONG_MAX;
	dfs(n, 0, 1, 0, buho, v);

	flag = 0;
	v.clear();
	for (int i = 0; i < 10; i++) {
		visit[i] = 0;
	}

	cmp = LLONG_MIN;
	dfs(n, 9, -1, 0, buho, v);
	
	cout << Mans << endl << mans << endl;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, j; //for문 변수 -> longlong필요한지 확인
	int n; cin >> n;
	vector<char> buho;
	for (int i = 0; i < n; i++) {
		char a; cin >> a;
		buho.push_back(a);
	}
	Solution(n,buho);

	return 0;
}