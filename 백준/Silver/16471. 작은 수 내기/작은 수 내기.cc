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
#include <cmath>
#include <sstream>


using namespace std;

/*struct type_name {

}srt;*/

//vector <type> vec;
//stack <type> stk;
//queue <type> q;
//string str;
//map <key_type,value_type> m;
int ju[100005];
int boss[100005];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int i, j;//for문변수-->가끔식 long으로
	int n; cin >> n;
	int winnable = (n + 1) / 2; //과반이상이겨야함
	//for(i=0;i<n;i++) {}
	//for(i=0;i<n;i++) { for(j=0;j<n;j++) { } }
	for (i = 1; i <= n; i++) cin >> ju[i];
	for (i = 1; i <= n; i++) cin >> boss[i];
	sort(ju + 1, ju + 1 + n,greater<int>());
	sort(boss + 1, boss + 1 + n, greater<int>());
	int cnt = 0;
	for (i = 1; i <= (n + 1) / 2; i++) {
		if (ju[(n + 1) / 2 + i - 1] < boss[i]) cnt++;
		//cout << ju[i] << " " << boss[i] << endl;
	}
	if (cnt == winnable) cout << "YES\n";
	else cout << "NO\n";
	return 0;
}