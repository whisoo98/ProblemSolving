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
#define N 400005
#define ll long long
#define endl "\n"
#define MID(a,b) (a+b)/2

using namespace std;

int pi[N];

void getPi(string s) {
	int len = s.length();
	int mat = 0;
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

bool kmp(string s,int len) {
	int l = s.length();
	int mat = 0;
	int cnt = 0;
	for (int i = len; i < l; i++) {
		//cout << i << " "<<s[i]<<" "<<s[mat]<<endl;
		if (!pi[i])continue;
		if (s[i] == s[mat]) {
			mat++;
			if (mat == len) {
				cnt++;
				mat = pi[mat-1];
				break;
			}
		}
		else if(mat!=0){
			
			i--;
			mat = pi[mat - 1];
		}
	}
	return cnt;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, j; //for문 변수 -> longlong필요한지 확인
	string tmp; cin >> tmp;
	string s;
	int len = tmp.length();
	for (i = 0; i < len; i++) {
		//printf("%d %d\n", s[i], '0');
		if (tmp[i] >='0' && tmp[i] <= '9') {
			continue;
		}
		s += tmp[i];
	}
	//sys.pause();
	//_sleep(1);
	
	cin >> tmp;
	len = tmp.length();
	tmp += s;
	getPi(tmp);
	
	if(kmp(tmp, len)) cout<<1;
	else cout << 0;
	//cout << s << " " << tmp << endl;
	//if (s.find(tmp) == string::npos) cout << 0;
	//else cout << 1;

	


	return 0;
}