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
#define INF 987654321
using namespace std;

vector<string> MBTI = {
	"ISTJ",
	"ISFJ",
	"INFJ",
	"INTJ",
	"ISTP",
	"ISFP",
	"INFP",
	"INTP",
	"ESTP",
	"ESFP",
	"ENFP",
	"ENTP",
	"ESTJ",
	"ESFJ",
	"ENFJ",
	"ENTJ"
};

map<string, int> mbti;
map<pair<string, string>, int> cmp_mbti;
//vector<string> cmp_mbti[20];
int cnt_mbti[20];

void preProcess() {
	for (int i = 0; i < 16; i++) {
		mbti.insert({ MBTI[i],i });
	}

	for (int i = 0; i < 16; i++) {
		string s1 = MBTI[i];
		for (int j = 0; j < 16; j++) {
			int diff = 0;
			string s2 = MBTI[j];
			for (int k = 0; k < 4; k++) {
				if (s1[k] != s2[k]) {
					diff++;
				}
			}
			//cmp_mbti[mbti[s1]].push_back(s2);
			cmp_mbti.insert({ {s1,s2},diff });
		}
	}
}

void Solution(int n, vector<string>& std) {
	int ans = INF;
	int base_mbti = max_element(cnt_mbti, cnt_mbti + 20) - cnt_mbti; // the most number of std.
	if (cnt_mbti[base_mbti] >= 3) {
		ans = 0;
	}
	else {
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				for (int k = j + 1; k < n; k++) {
					string mbti1 = std[i];
					string mbti2 = std[j];
					string mbti3 = std[k];
					ans = min(ans, cmp_mbti[{mbti1, mbti2}] + cmp_mbti[{mbti2, mbti3}] + cmp_mbti[{mbti3, mbti1}]);
				}
			}
		}
	}
	cout << ans << endl;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	preProcess();
	int T; cin >> T;
	while (T--) {
		int n; cin >> n;
		memset(cnt_mbti, 0, sizeof(cnt_mbti));
		vector<string> std;
		for (int i = 0; i < n; i++) {
			string s; cin >> s;
			int mbti_num = mbti[s];
			cnt_mbti[mbti_num]++;
			std.push_back(s);
		}
		Solution(n, std);
	}

	return 0;
}