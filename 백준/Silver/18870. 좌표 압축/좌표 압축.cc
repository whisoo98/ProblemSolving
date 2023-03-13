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
#define N 1000005
#define ll long long
#define endl "\n"
#define MID(a,b) (a+b)/2

using namespace std;


map<int, int>m;
vector<int>v;
int arr[N];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, j; //for문 변수 -> longlong필요한지 확인
	int n; cin >> n;
	for (i = 0; i < n; i++) {
		cin >> arr[i];
		v.push_back(arr[i]);
	}
	sort(v.begin(), v.end());
	//cout << "!";
	//if (unique(v.begin(), v.end()) != v.end()) {
		v.erase(unique(v.begin(), v.end()), v.end());
		
	//}
	//sort(v.begin(), v.end());
		int size = v.size();
	for (i = 0; i < size; i++) {
		m.insert({ v[i], i });
		/*if (m.find(v[i]) == m.end()) {
			m.insert({ v[i],i });
		}
		else {
			m[v[i]] = min(m[v[i]], i);
		}*/
	}
	for (i = 0; i < n; i++) {
		cout << m[arr[i]] << " ";
	}
	return 0;
}