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


ll ans;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, j; //for문 변수 -> longlong필요한지 확인
	int n; cin >> n;
	stack<pair<int,int>> stk; // height, count
	for (int i = 0; i < n; i++) {
		int height; cin >> height;
		int add = 0;
		while (1) {
			if (stk.empty()) {
				stk.push({ height,1 });
				break;
			}
			else {
				if (stk.top().first < height) {
					ans += stk.top().second;
					stk.pop();
				}
				else if(stk.top().first == height){
					int temp = stk.top().second;
					ans += stk.top().second;
					stk.pop();
					if(stk.size())
						ans++;
					stk.push({ height,temp + 1 });
					break;
				}
				else if (stk.top().first > height) {
					ans++;
					stk.push({ height,1 });
					break;
				}
			}
		}
	}
	//while (stk.size()>1) {
	//	//cout << stk.top().first << " ";
	//	//ans += stk.top().second;
	//	ans++;
	//	stk.pop();
	//}
	cout << ans << endl;
	return 0;
}