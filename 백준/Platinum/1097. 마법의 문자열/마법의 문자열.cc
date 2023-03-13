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
#define N 200
#define ll long long
#define endl "\n"
#define MID(a,b) (a+b)/2

using namespace std;

int pi[N];
void getPi(string s) {
	int mat = 0;
	int len = s.length();
	for (int i = 1; i < len; i++) {
		if (s[i] == s[mat]) {
			pi[i] = ++mat;
		}
		else if (mat != 0) {
			i--;
			mat = pi[mat - 1];
		}
	}
}

int kmp(string s) {
	int len = s.length();
	string cmp = s + s;
	int ans = 0;
	int temp = len - pi[len - 1];
	//cout << s << " "<<temp<<endl;
	
	for (int i = 0, trial = 0, mat = 0; i < len * 2-1; i++) {
		if (s[mat] == cmp[i]) {
			//cout << s[mat] << " " << cmp[i] << endl;
			//cout << "!";
			mat++;
			if (mat == len) {
				//cout << i << " " << len << endl;
				ans++;
				mat = 0;
				trial++;
				i = trial * temp;
				i--;
				//cout << endl;
			}
		}
		else {
			mat = 0;
			trial++;
			i = trial * temp;
			i--;
		}
	}
	//cout << ans;
	//cout << endl;
	return ans;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, j; //for문 변수 -> longlong필요한지 확인
	int n; cin >> n;
	vector<string> v;
	int fac = 1;
	int arr[10];
	for (i = 0; i < n; i++) {
		string s; cin >> s;
		v.push_back(s);
		arr[i] = i;
		fac = fac * (i + 1);
	}
	int k; cin >> k;
	ll cnt = 0;
	for (i = 1; i <= fac; i++) {
		string temp = "";
		for (j = 0; j < n; j++) {
			temp += v[arr[j]];
		}
		//cout << temp << endl;
		getPi(temp);
		if (k == kmp(temp)) cnt++;
		next_permutation(arr, arr + n);
		
	}
	cout << cnt;
	return 0;
}