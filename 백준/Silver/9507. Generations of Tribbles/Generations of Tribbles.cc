#include <stdio.h>
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


using namespace std;

/*struct type_name {

}srt;*/

//vector <type> vec;
//stack <type> stk;
//queue <type> q;
//string str;
//map <key_type,value_type> m;
long long fibo[100];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int i, j;//for문변수-->가끔식 long으로
	int T;
	cin >> T;
	fibo[0] = 1;
	fibo[1] = 1;
	fibo[2] = 2;
	fibo[3] = 4;
	for (i = 4; i <= 67; i++) {
		fibo[i] = fibo[i - 1] + fibo[i - 2] + fibo[i - 3] + fibo[i - 4];
	}
	while (T--) {
		int a;
		cin >> a;
		cout << fibo[a] << "\n";
	}

	return 0;
}