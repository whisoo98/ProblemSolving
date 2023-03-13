#include <iostream>
#include <algorithm>
#include <functional>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <string>
#include <queue>
#include <stack>
#include <map>
#include <vector>
#include <set>
#include <sstream>
#include <ctime>

using namespace std;

int V, E;
vector<int> edge[1005];
int in[1005];
int chk[1005];
queue<int> ans;
queue<int> temp;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, j; //for문 변수 -> longlong필요한지 확인
	cin >> V >> E;
	for (i = 1; i <= E; i++) {
		int n; cin >> n;
		int a; cin >> a;
		for (j = 2; j <= n; j++) {
			int b; cin >> b;
			in[b]++;
			edge[a].push_back(b);
			a = b;
		}
	}
	
	for (int k = 1; k <= V; k++) {
		
		for (i = 1; i <= V; i++) {
			if (in[i] == 0 && chk[i] == 0) {
				//ans.push(i);
				temp.push(i);
				chk[i]++;
				//cout << "i : " << i << endl;
			}
		}
		
		while (!temp.empty()) {
			int now = temp.front();
			for (auto it : edge[now]) {
				in[it]--;
			}
			temp.pop();
			ans.push(now);
		}
	}
	if (ans.size() != V) {
		cout << 0;
	}
	else {
		while (!ans.empty()) {
			cout << ans.front() << "\n";
			ans.pop();
		}
	}
	return 0;
}