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
#define N 1'005
#define ll long long
#define endl "\n"
#define MID(a,b) (a+b)/2

using namespace std;

//int class_stu[N][N];
vector<pair<int, int>> class_stud;

int twoPointer(int n, int m) {
	int cls_check[N];
	for (int i = 0; i < N; i++) {
		cls_check[i] = 0;
	}
	int diff = INT_MAX;
	int left, right;
	int num_cls = 0;
	for (int i = 0, j = 1; i <j && j <n*m;) {
		if (i == 0 && num_cls==0) {
			num_cls++;
			left = i;
			cls_check[class_stud[i].second]++;
			continue;
		}
		if (num_cls < n) {
			if (cls_check[class_stud[j].second]) {
				// aleady checked cls
				// do nothing
				cls_check[class_stud[j].second]++;
				j++;
				continue;
			}
			// need to check cls
			cls_check[class_stud[j].second]++;
			right = j++;
			num_cls++;
		}
		else {
			diff = min(diff, class_stud[right].first - class_stud[left].first);
			i++;
			cls_check[class_stud[left].second]--;
			if (!cls_check[class_stud[left].second]) {
				num_cls--;
			}
			left = i;
		}
	}
	return diff;
}

void Solution(int n, int m) {
	int ans = twoPointer(n, m);
	cout << ans << endl;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, j; //for문 변수 -> longlong필요한지 확인
	int n, m; cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			//cin >> class_stu[i][j];
			int stud; cin >> stud;
			class_stud.push_back({ stud,i });
		}
		//sort(class_stu[i] + 1, class_stu[i] + 1 + m);
	}
	sort(class_stud.begin(), class_stud.end());
	Solution(n, m);
	return 0;
}