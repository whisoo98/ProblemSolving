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

vector<string> strings;



int isPalin(string s) {
	string cmp_s = s;
	reverse(cmp_s.begin(), cmp_s.end());
	int ret = 0;
	int len = s.length();
	for (int i = 0; i < len; i++) {
		ret = s[i] - cmp_s[i]; // check whether s[i] is same with cmp_s[i].
		if (ret) {
			ret = i + 1; // To delete index.
			break;
		}
	}
	if (ret) { // not Palin
		string temp = s; // Save string.
		int temp_ret = ret; // Save to delete index.
		s.erase(ret - 1, 1);
		cmp_s = s;
		reverse(cmp_s.begin(), cmp_s.end());
		ret = 0;
		len = s.length();
		for (int i = 0; i < len; i++) {
			ret = s[i] - cmp_s[i]; // check whether s[i] is same with cmp_s[i].
			if (ret) {
				ret = i + 1; // To delete index.
				break;
			}
		}
		if (!ret) return 1;
		
		cmp_s = temp;
		reverse(cmp_s.begin(), cmp_s.end());
		cmp_s.erase(temp_ret - 1, 1);
		s = cmp_s;
		reverse(s.begin(), s.end());
		ret = 0;
		len = s.length();
		for (int i = 0; i < len; i++) {
			ret = s[i] - cmp_s[i]; // check whether s[i] is same with cmp_s[i].
			if (ret) {
				ret = i + 1; // To delete index.
				break;
			}
		}
		if (ret) return 2;
		else return 1;
	}
	else return ret; // It is palin.
}

void Solution(int n) {
	for (auto s : strings) {
		cout << isPalin(s) << endl;
	}

}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, j; //for문 변수 -> longlong필요한지 확인
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		string s; cin >> s;
		strings.push_back(s);
	}
	Solution(n);
	return 0;
}