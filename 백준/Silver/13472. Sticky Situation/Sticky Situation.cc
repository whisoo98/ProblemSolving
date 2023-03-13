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
long long arr[30000];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int i, j;//for문변수-->가끔식 long으로
	int n; cin >> n;
	for (i = 0; i < n; i++) cin >> arr[i];
	sort(arr, arr + n, greater<long long>());
	for (i = 0; i < n - 2; i++) {
		if (arr[i] < arr[i + 1] + arr[i + 2]) {
			cout << "possible";
			return 0;
		}
	}
	cout << "impossible";
	//for(i=0;i<n;i++) {}
	//for(i=0;i<n;i++) { for(j=0;j<n;j++) { } }

	return 0;
}