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
#define N 1000005
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
		else if (mat) {
			i--;
			mat = pi[mat - 1];
		}
	}
}

int kmp(string s) {
	int len = s.length();
	int len2 = pi[len - 1];
	int ret = 0;
	int mat = 0;
	while (len2) {
		
		for (int i = 0; i < len; i++) {
			if (s[i] == s[mat]) {
				++mat;
				if (mat == len2) {
					ret++;
					mat = pi[mat - 1];
				}
			}
			else if (mat) {
				i--;
				mat = pi[mat - 1];
			}
		}
		if (ret >= 3) break;
		ret = 0;
		mat = 0;
		len2 = pi[len2 - 1];
	}
	return len2;
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, j; //for문 변수 -> longlong필요한지 확인
	string s; cin >> s;
	//pi[0] = 1;
	getPi(s);
	
	int len = s.length();
	int ans = kmp(s);
	
	if (ans == 0) {
		cout << -1;
	}
	else {
        if(pi[len-1]*2>len){
          ans=pi[pi[len-1]-1];  
        } 
        //ans = pi[pi[len-1]-1];
        cout << s.substr(0, ans);
    }
	return 0;
}