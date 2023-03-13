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

vector <int> vec;
vector <char> giho;
stack <int> stk;
//queue <type> q;
//string str;
//map <key_type,value_type> m;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int i, j;//for문변수-->가끔식 long으로
	int n;
	scanf("%d", &n);
	vec.push_back(999999);
	for (i = 1; i <= n; i++) {
		int temp;
		scanf("%d", &temp);
		vec.push_back(temp);
		//cout << vec[i] << endl;
	}
/*	while (1) {

	}*/
//	cout << "!";
	int temp = 1;
	for (i = 1; i <= n; i++) {
		stk.push(i);
		giho.push_back('+');
		//cout << "!";
		//cout << giho[i - 1];
		//cout << i << endl;
		while (stk.top() == vec[temp]) {
			stk.pop();
			temp++;
			//vec.erase(vec.begin() + 1);
			giho.push_back('-');
			//cout << i << i;
			if (stk.empty()) break;
		}
	}
	//cout << "!";
	//for (i = 0; i < n; i++) cout << giho[i];
	if (stk.empty()) {
		for (i = 0; i < 2*n; i++) printf("%c\n", giho[i]);
	}
	else printf("NO");

	return 0;
}