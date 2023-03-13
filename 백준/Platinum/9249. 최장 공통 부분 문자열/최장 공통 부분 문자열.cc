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
#define N 400'005
#define ll long long
#define endl "\n"
#define MID(a,b) (a+b)/2

using namespace std;

int t;
int SA[N];
int tg[N];
int g[N];
int Rank[N];
int LCP[N];

bool cmp(int x, int y) {
	if (g[x] == g[y]) {
		return g[x + t] < g[y + t];
	}
	return g[x] < g[y];
}

void getSA(string s) {
	t = 1;
	int len = s.length();

	for (int i = 0; i < len; i++) {
		SA[i] = i;
		g[i] = s[i] - 'a';
	}

	while (t <= len) {
		g[len] = -1;
		sort(SA, SA + len, cmp);
		tg[SA[0]] = 0;

		for (int i = 1; i < len; i++) {
			if (cmp(SA[i - 1], SA[i])) {
				tg[SA[i]] = tg[SA[i - 1]] + 1;
			}
			else tg[SA[i]] = tg[SA[i - 1]];
		}

		for (int i = 0; i < len; i++) {
			g[i] = tg[i];
		}

		t *= 2;
	}
}

void getLCP(string s,string temp) {
	int len = s.length();
	int mat = 0;
	
	for (int i = 0; i < len; i++) {
		Rank[SA[i]] = i;
	}
	
	for (int i = 0; i < len; i++) {
		
		int k = Rank[i];
		if (k) {
			int j = SA[k - 1];
			
			while (s[i + mat] == s[j + mat]) {
				mat++;
			}
			
			LCP[k] = mat;
			if (mat)mat--;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//cout.tie(NULL);

	int i, j; //for문 변수 -> longlong필요한지 확인
	string s; cin >> s;
	string temp; cin >> temp;
	string C;
	if (s.length() < temp.length()) {
		C = s;
		s = temp;
		temp = C;
	}
	int len1 = s.length();
	s += '!';
	s += temp;
	getSA(s);
	getLCP(s, temp);
	//cout << s << endl;
	/*printf("\n[Suffix Array]\n");

	for (int i = 0; i < s.length(); i++)
		cout << s.substr(SA[i]) << endl;
		//printf("%s\n", str + SA[i]);

	printf("\n[Suffix Array Order]\n");
	for (int i = 0; i < s.length(); i++)
		printf("%d ", SA[i] + 1);

	//while(1)
	cout << endl;*/

	int m = 0;
	int len = s.length();
	string ans;
	for (i = 1; i < len; i++) {

		//&& (SA[i] >= len1 || SA[i - 1] >= len1)
		if ((SA[i] < len1 && SA[i - 1] > len1)
			|| (SA[i] > len1 && SA[i-1] < len1)) {
			if (LCP[i] > m) {
				//m = max(m,min(LCP[i],len1-SA[i]));
				//m = min(LCP[i], len1 - SA[i]);

				m = LCP[i];
				ans = s.substr(SA[i], m);


			}
		}
	}

	cout << m << endl << ans << endl;
	return 0;
}