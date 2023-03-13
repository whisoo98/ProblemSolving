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
#include <unordered_set>
#define N 1'000'005
#define ll long long
#define endl "\n"
#define MID(a,b) (a+b)/2
#define INF INT_MAX
using namespace std;

unordered_multiset<ll> unset;


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, j; //for문 변수 -> longlong필요한지 확인
	int T; cin >> T;
	while (T--) {
		int n; cin >> n;
		priority_queue<ll> maxq;
		priority_queue<ll, vector<ll>, greater<ll>> minq;
		int D = 0;
		int I = 0;
		for (int i = 0; i < n; i++) {
			char cmd; ll num;
			cin >> cmd >> num;
			if (cmd == 'I') {
				I++;
				maxq.push(num);
				minq.push(num);
				unset.insert(num);
			}
			else {
				if (num == 1) {
					if (maxq.size()) {
						D++;
						if (D == I) {
							while (maxq.size()) maxq.pop();
							while (minq.size()) minq.pop();
							D = 0;
							I = 0;
							unset.clear();

						}
						else {
							while (1) {
								ll temp = maxq.top(); maxq.pop();
								auto iter = unset.find(temp);
								if (iter == unset.end()) {
									continue;
								}
								else {
									unset.erase(iter);
									break;
								}
							}
						}
					}
					else {
						while (maxq.size()) maxq.pop();
						while (minq.size()) minq.pop();
						D = 0;
						I = 0;
						unset.clear();
					}
				}
				else {
					if (minq.size()) {
						D++;
						if (D == I) {
							while (maxq.size()) maxq.pop();
							while (minq.size()) minq.pop();
							D = 0;
							I = 0;
							unset.clear();

						}
						else {
							while (1) {
								ll temp = minq.top(); minq.pop();
								auto iter = unset.find(temp);
								if (iter == unset.end()) {
									continue;
								}
								else {
									unset.erase(iter);
									break;
								}
							}
						}
					}
					else {
						while (maxq.size()) maxq.pop();
						while (minq.size()) minq.pop();
						D = 0;
						I = 0;
						unset.clear();

					}
				}
			}
		}
		if (maxq.size()) {
			ll M, m;
			while (1) {
				M = maxq.top();
				if (unset.count(M)) break;
				maxq.pop();
			}
			while (minq.size()) {
				m = minq.top();
				if (unset.count(m)) break;
				minq.pop();
			}
			cout << M << " " << m << endl;
			//cout << maxq.top() << " " << minq.top() << endl;
		}
		else {
			cout << "EMPTY" << endl;
		}
	}
	return 0;
}