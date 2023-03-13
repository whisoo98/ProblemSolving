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

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int i, j;//for문변수-->가끔식 long으로
	//int n; scanf("%d", &n);
	int a, b, v; cin >> a >> b >> v;

	if (!(v - a)) {
		cout << 1<<endl;
	}
	else {
		int mok = (v - a) / (a - b);
		int rest = (v - a) % (a - b);
		if(rest)		cout << mok + 2;
		else cout << mok + 1;
	}
	//for(i=0;i<n;i++) {}
	//for(i=0;i<n;i++) { for(j=0;j<n;j++) { } }

	return 0;
}