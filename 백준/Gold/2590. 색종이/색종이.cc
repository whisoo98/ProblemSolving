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
#define N 10
#define ll long long
#define endl "\n"
#define MID(a,b) (a+b)/2

using namespace std;


int color_paper[N];


int pastePaper(int size) {
	int need_num_paper = 0;
	int rest = 36;
	switch (size)
	{
	case 5:
		while (color_paper[size]) {
			need_num_paper++;
			color_paper[size]--;
			color_paper[1] -= 36 - size*size;
			color_paper[1] = max(color_paper[1], 0);
		}
		break;
	case 4:
		while (color_paper[size]) {
			need_num_paper++;
			color_paper[size]--;
			if (color_paper[2] > 0) {
				color_paper[2] -= (36 - size * size) / (2 * 2);
				if (color_paper[2] < 0) {
					int neg = abs(color_paper[2]);
					color_paper[1] -= neg * 4;
					color_paper[1] =max(color_paper[1],0);
					color_paper[2] = max(color_paper[2], 0);
				}
			}
			else {
				color_paper[1] -= (36 - size * size);
				color_paper[1] = max(color_paper[1], 0);
			}
		}
		break;
	case 3:
		need_num_paper += color_paper[size] / 4;
		color_paper[size] %= 4;
		rest = 36;
		if (color_paper[size] == 1) {
			need_num_paper++;
			rest -= 9;
			for (int i = 0; i < 5 && color_paper[2]; i++) {
				color_paper[2]--;
				rest -= 4;
			}
			for (int i = 0; i < rest && color_paper[1]; i++) {
				color_paper[1]--;
			}
		}
		else if (color_paper[size] == 2) {
			need_num_paper++;
			rest -= 9 * 2;
			for (int i = 0; i < 3 && color_paper[2]; i++) {
				color_paper[2]--;
				rest -= 4;
			}
			for (int i = 0; i < rest && color_paper[1]; i++) {
				color_paper[1]--;
			}
		}
		else if (color_paper[size] == 3) {
			need_num_paper++;
			rest -= 9 * 3;
			for (int i = 0; i < 1 && color_paper[2]; i++) {
				color_paper[2]--;
				rest -= 4;
			}
			for (int i = 0; i < rest && color_paper[1]; i++) {
				color_paper[1]--;
			}
		}
		break;
	case 2:
		need_num_paper += color_paper[size] / 9;
		color_paper[size] %= 9;
		if (color_paper[size]) {
			need_num_paper++;
			rest = 36 - color_paper[size] * 4;
			color_paper[1] -= rest;
			color_paper[1] = max(color_paper[1], 0);
		}
		break;
	case 1:
		need_num_paper += color_paper[size] / 36;
		color_paper[size] %= 36;
		if (color_paper[size])
			need_num_paper++;
		break;
	default:
		break;
	}
	return need_num_paper;
}

void Solution() {
	int ans = 0;
	ans += color_paper[6];
	for (int i = 5; i > 0; i--) {
		ans += pastePaper(i);
	}
	cout << ans << endl;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, j; //for문 변수 -> longlong필요한지 확인
	for (int i = 1; i <= 6; i++) {
		cin >> color_paper[i];
	}
	Solution();
	return 0;
}