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
#define N 505
#define ll long long
#define endl "\n"
#define MID(a,b) (a+b)/2

using namespace std;

int rain[N];
vector<int> heights[N];
int visit[N];
int ans = 0;
int maxy = -1;
void Solution(int y, int x) {
	int sum = 0;
	int tleft=987654321, tright=-1;
	int left, right;
	for (int i = maxy; i >= 0; i--) {
		int sz = heights[i].size();
		if (sz == 0) continue;
		/*sort(heights[i].begin(), heights[i].end());
		if (i > 0) {
			for (int j = 0; j < sz; j++) {
				heights[i - 1].push_back(heights[i][j]);
			}
		}*/
		left = heights[i][0];
		left = min(tleft, heights[i][0]);

		right = heights[i][sz-1];
		right = max(tright, heights[i][sz-1]);
		tleft = left;
		tright = right;
		/*if (sz == 1) 
			continue;*/

		int add = 0;
		for (int j = left; j <= right; j++) {
			if (visit[j]) continue;
			add += i - min(i, rain[j]);
			visit[j] = 1;
		}

		sum += add;
		
	}
	/*cout << "sum : "<<sum << endl;
	if (ans != sum) {
		cout << "WRONG" << endl;
	}*/
	cout << sum << endl;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, j; //for문 변수 -> longlong필요한지 확인
	//while (1) {
		int y, x; cin >> y >> x;
		for (int i = 0; i < x; i++) {
			cin >> rain[i];
			heights[rain[i]].push_back(i);
			maxy = max(maxy, rain[i]);
		}
		Solution(y, x);

		/*cin >> ans;
		Solution(y, x);
		maxy = -1;
		for (int i = 0; i < N; i++) {
			heights[i].clear();
			visit[i] = 0;
			rain[i] = 0;
		}
	}*/
	return 0;
}