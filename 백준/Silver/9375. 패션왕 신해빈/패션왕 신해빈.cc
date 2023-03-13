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
#include <iterator>
using namespace std;




int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, j; //for문 변수 -> longlong필요한지 확인
	int T; cin >> T;
	while (T--) {
		int n; cin >> n;
		if (n == 0) {
			cout << "0\n";
			continue;
		}
		multimap<string, string> m;
		set<string> s;
		string type, name;
		for (i = 0; i < n; i++) {
			cin >> name >> type;
			m.insert({ type,name });

			if (s.find(type) == s.end()) {
				s.insert(type);
			}
		}
		long long mult = 1;
		for (auto it = s.begin(); it != s.end(); it++) {
			auto range = m.equal_range(*it);
			mult *= distance(range.first, range.second) + 1;
		}
		cout << mult - 1 << "\n";


	}
	
	return 0;
}