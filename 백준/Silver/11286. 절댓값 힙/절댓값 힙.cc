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

using namespace std;
priority_queue<int> pq_pos;
priority_queue<int> pq_neg;



int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, j; //for문 변수 -> longlong필요한지 확인
	int n; cin >> n;
	for (i = 1; i <= n; i++) {
		int a; cin >> a;
		if (a) {
			if (a > 0) {
				pq_pos.push(-a);
			}
			else {
				pq_neg.push(a);
			}
			
		}
		else {
			if (pq_pos.empty() && pq_neg.empty()) {
				cout << 0 << "\n";
			}
			else if (!pq_pos.empty() && pq_neg.empty()) {
				cout << -pq_pos.top() << "\n";
				pq_pos.pop();
			}
			else if (pq_pos.empty() && !pq_neg.empty()) {
				cout << pq_neg.top() << "\n";
				pq_neg.pop();
			}
			else {
				int pos = -pq_pos.top();
				int neg = pq_neg.top();
				if (abs(pos) == abs(neg)) {
					cout << neg << "\n";
					pq_neg.pop();
				}
				else if (abs(pos) < abs(neg)) {
					cout << pos << "\n";
					pq_pos.pop();
				}
				else {
					cout << neg << "\n";
					pq_neg.pop();
				}
			}
		}
	}
	return 0;
}