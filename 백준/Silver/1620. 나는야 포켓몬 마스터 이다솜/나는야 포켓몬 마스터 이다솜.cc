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

map <int,string> poket1;
map <string, int> poket2;
char num[11] = { "0123456789" };
int main()
{
	//ios_base::sync_with_stdio(false);
	//cin.tie(NULL);
	//cout.tie(NULL);
	int i, j;//for문변수-->가끔식 long으로
	int n, m;
	scanf("%d %d",&n,&m);//n은 도감 수 m은 문제수
	for (i = 1; i <= n; i++) {
		char str[25];
//		cin >> str;
		scanf("%s", str);
		poket1[i] = str;
		poket2[str] = i;
	}
	for (i = 1; i <= m; i++) {
		//string str;
		char str[10] = { "" };
		scanf("%s", str);
		int temp;
		int chk = 0;
		//cout << str;
		for (j = 0; j < 10; j++) {
			if (str[0] == num[j]) {
				chk = 1;
				temp = atoi(str);
				break;
			}
		}
		//cout << "chk : "<<chk << endl;
		if (chk) {
			//cout << poket1[temp] << endl;
			printf("%s\n", poket1[temp].c_str());
		}
		else {
			//cout << poket2[str] << endl;
			printf("%d\n", poket2[str]);
		}
	}
	return 0;
}