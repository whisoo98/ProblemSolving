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
#define N 35
#define NN 40'005
#define ll long long
#define endl "\n"
#define MID(a,b) (a+b)/2

using namespace std;

int chu[N];
int beads[N];
int grams[NN];
void DP(int n, int m) {
	vector<int> gram_list;
	gram_list.push_back(chu[1]);
	grams[chu[1]] = 1;
	for (int i = 2; i <= n; i++) {
		int sz = gram_list.size();
		for (int j = 0; j < sz;j++) {
			int gram = gram_list[j];

			int new_gram_pos = gram + chu[i];
			int new_gram_neg = abs(gram - chu[i]);
			if (grams[chu[i]] == 0) {
				gram_list.push_back(chu[i]);
				grams[chu[i]] = 1;
			}
			if (grams[new_gram_pos] == 0) {
				gram_list.push_back(new_gram_pos);
				grams[new_gram_pos] = 1;
			}
			if (grams[new_gram_neg] == 0) {
				gram_list.push_back(new_gram_neg);
				grams[new_gram_neg] = 1;
			}
		}
	}
}
void Solution(int n, int m) {
	DP(n, m);
	for (int i = 1; i <= m; i++) {
		if (grams[beads[i]]) cout << "Y ";
		else cout << "N ";
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, j; //for문 변수 -> longlong필요한지 확인
	int n; cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> chu[i];
	}
	int m; cin >> m;
	for (int i = 1; i <= m; i++) {
		cin >> beads[i];
	}
	Solution(n, m);
	return 0;
}