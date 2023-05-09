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
#define N 200'005
#define ll long long
#define endl "\n"
#define MID(a,b) (a+b)/2

using namespace std;


int ans = 0;
//vector<tuple<int, int, int>> answer;
vector<pair<int,int>> answer;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, j; //for문 변수 -> longlong필요한지 확인
	int n; cin >> n;
	string s; cin >> s;
	stack<char> paren1;
	stack<int> index1;
	int len = s.length();
	answer.push_back({ n+5, n+4 });
	for (int i = 0; i < len; i++) {
		if (s[i] == '(') {
			paren1.push('(');
			index1.push(i);
		}
		else {
			if (paren1.size()) {
				int left = index1.top();
				index1.pop();
				paren1.pop();
				//ans = max(ans, i - left + 1);
				answer.push_back({ left,i });
			}
		}
	}
	sort(answer.begin(), answer.end());
	int sz = answer.size();
	int sum = 0;
	for (int i = 0; i < sz-1;i++) {
		sum = 0;
		int left = answer[i].first;
		int right = answer[i].second;
		for (int j = i+1; j < sz-1; j++) {
			i = j-1;
			if (answer[j].second < right) {
				continue;
			}
			if (answer[j].first == right + 1) {
				right = answer[j].second;
			}
			else {
				break;
			}
		}
		//cout << left << " " << right << endl;
		sum = right - left + 1;
		ans = max(ans,sum);
	}
	cout << ans << endl;
	return 0;

}