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
#define N 25
#define ll long long
#define endl "\n"
#define MID(a,b) (a+b)/2
#define INF 987654321
using namespace std;

int arr[N][N];
int chk[N];
int ans = INF;
int start = 0, link = 0;

void func(deque<int>&v, int* score) {
	int size = v.size();
	int i, j;
	for (i = 0; i < size; i++) {
		for (j = 0; j < size; j++) {
			(*score) += arr[v[i]][v[j]];
			//(*score) += arr[v[j]][v[i]];

		}
	}
	//cout << *score << endl;
}
void dfs(deque<int>&v1, deque<int>&v2, int lv, int n) {
	if (v1.size() == n) {
		start = 0;
		link = 0;
		v2.clear();
		int chk[N];
		for (int i = 1; i <= 20; i++) chk[i] = 0;
		
		for (auto it : v1) {
			chk[it] = 1;
		}

		for (int i = 1; i <= 2*n; i++) {
			if (!chk[i]) v2.push_back(i);
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				start += arr[v1[i]][v1[j]];
				link += arr[v2[i]][v2[j]];
			}
		}
		/*cout << "v1\t";
		for (auto it : v1) {
			cout << it << " ";
		}
		//cout << endl;
		//cout << "v2\t";
		for (auto it : v2) {
			cout << it << " ";
		}
	//	cout << endl;*/
		ans = min(ans, abs(start - link));
		//v1.pop_back();

	}
	else {
		for (int i = lv; i <= n * 2; i++) {
			v1.push_back(i);
			dfs(v1, v2, i + 1, n);
			v1.pop_back();
		}
		//v1.pop_back();

	}

}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, j; //for문 변수 -> longlong필요한지 확인
	int n; cin >> n;
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++) {
			cin >> arr[i][j];
		}
	}
	//for (i = 1; i <= n*(n-1)/4; i++) {
		deque<int>v1;
		deque<int>v2;
		dfs(v1, v2, 1, n / 2);
		/*for (int k = 1; k <= n; k++) {
			chk[k] = 0;
		}
		bool check = false;
		int sum = (n - 1 - i)*(n - i) / 2;

		for (j = i; j <= n + 1; j++) {
			if (v1.size() < n / 2) {
				v1.push_back(j);
				chk[j] = 1;
				continue;
			}
			else {
				
				if (check == false) {
					for (int k = 1; k <= n; k++) {
						if (!chk[k]) v2.push_back(k);
					}
					check = true;
				}
				func(v1, &start);
				func(v2, &link);
				for (auto it : v1) {
					cout << it << " ";
				}
				cout << endl;
//				cout << start << endl;
				for (auto it : v2) {
					cout << it << " ";
				}
				cout << endl;
//				cout << link << endl;
				v2.pop_front();
				v2.push_back(v1.back());
				v1.pop_back();
				v1.push_back(j);
				ans = min(ans, abs(start - link));
				cout << ans << endl;
			}
		}*/
	
	cout << ans;
	return 0;
}