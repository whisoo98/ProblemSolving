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
#define N 50
#define ll long long
#define endl "\n"
#define MID(a,b) (a+b)/2

using namespace std;

string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
string ans = "I'm Sorry Hansoo";
int cnt[N];
string isPalin(string name) {
	int sz = name.length();
	for (int i = 0; i < sz; i++) {
		cnt[name[i] - 'A']++;
	}
	int num_alphabet = alphabet.length();
	int chk = 0;
	int idx = -1;
	for (int i = 0; i < num_alphabet; i++) {
		if (cnt[i] % 2 == 1) {
			chk++;
			idx = i;
		}
	}
	if (chk >= 2) {
		return ans;
	}
	string left = "";
	string right = "";
	string center;
	for (int i = 0; i < num_alphabet; i++) {
		for (int j = 0; j < cnt[i] / 2; j++) {
			left = left + alphabet[i];
			right = alphabet[i] + right;
		}
		if (i == idx) {
			center = alphabet[i];
		}
	}
	return left + center + right;
}

void Solution(string name) {
	ans = isPalin(name);
	cout << ans << endl;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, j; //for문 변수 -> longlong필요한지 확인
	string name; cin >> name;
	Solution(name);

	return 0;
}