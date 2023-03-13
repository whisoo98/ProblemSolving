#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <functional>
#include <stdlib.h>
#include <string>
#include <queue>
#include <stack>
#include <map>
#include <climits>
#include <cstring>


using namespace std;

/*struct type_name {

}srt;*/

//vector <type> vec;
//stack <type> stk;
//queue <type> q;
//string str;
//map <key_type,value_type> m;

vector<long long>v;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int i, j;//for문변수-->가끔식 long으로
	long long n;
	int k, q;
	cin >> n >> k >> q;
	for (i = 0; i < q; i++) {
		v.clear();
		long long a, b; cin >> a >> b;
		long long M = max(a, b), m = min(a, b);
		if (k == 1) {
			cout << M - m << "\n";
		}
		else if (k == 2) {
			while (M > 0) {
				v.push_back(M);
				M = (M) / k;
			}
			/*cout << "V" << endl;
			for (j = 0; j < v.size(); j++) {
				cout << v[j] << " ";
			}
			cout << "\n";*/
			long long temp = m;
			int cnt = 0;
			while (find(v.begin(), v.end(), m) == v.end()) {
				m = (m) / k;
				cnt++;
			}
			int dist = (find(v.begin(), v.end(), m) - v.begin());
			cout << dist + cnt << "\n";
		}
		else {
			int plus = k - 2;
			while (M > 0) {
				v.push_back(M);
				M = (M + plus) / k;
			}
			long long temp = m;
			int cnt = 0;
			while (find(v.begin(), v.end(), m) == v.end()) {
				m = (m + plus) / k;
				cnt++;
			}
			int dist = (find(v.begin(), v.end(), m) - v.begin());
			cout << dist + cnt << "\n";
		}
	}

	//for(i=0;i<n;i++) {}
	//for(i=0;i<n;i++) { for(j=0;j<n;j++) { } }

	return 0;
}