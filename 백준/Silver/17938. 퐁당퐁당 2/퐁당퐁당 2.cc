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

using namespace std;




int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, j; //for문 변수 -> longlong필요한지 확인
	int n; cin >> n;
	deque<int> q;
	for (int i = 1; i <= n; i++) {
		q.push_back(i);
		q.push_back(i);
	}
	q.pop_front();
	q.push_back(1);
	int p, t; cin >> p >> t;
	t -= 2;
	int mok = t / (4 * n - 2);
	for (int i = 0; i < mok; i++) {
		q.push_front(q.back());
		q.pop_back();
	}
	t %= (4 * n - 2);
	int sub = 1;
	int flag = 1;
	for (int i = 0; i < t; i++) {

		sub += flag;
		int temp = sub; 
		while (temp) {
			temp--;
			int now = q.front();
			q.pop_front();
			q.push_back(now);
			//cout << now << " ";
		}
		//cout << endl;
		if (sub == 2 * n && flag == 1) {
			flag = -1;
		}
		else if(sub==1 && flag ==-1) {
			flag = 1;
		}
	}
	sub += flag;
	int ans = 0;
	while (sub) {
		sub--;
		int now = q.front();
		if (now == p) {
			ans = 1;
		}

		q.pop_front();
		q.push_back(now);
		//cout << now << " ";
	}
	//cout << endl;
	if (ans) {
		cout << "Dehet YeonJwaJe ^~^" << endl;
	}
	else {
		cout << "Hing...NoJam" << endl;
	}
	return 0;
}