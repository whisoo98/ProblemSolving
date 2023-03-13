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
#include<cstring>

using namespace std;

/*struct type_name {

}srt;*/

//vector <type> vec;
stack <double> stk;
//queue <type> q;
//string str;
//map <key_type,value_type> m;
char alphabet[30] = { "ABCDEFGHIJKLMNOPQRSTUVWXYZ" };
char str[105];
int arr[30];

 int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int i, j;//for문변수-->가끔식 long으로
	int n;
	scanf("%d", &n);
	scanf("%s", str);
	for (i = 0; i < n; i++) scanf("%d", &arr[i]);
	int len = strlen(str);
	int len2 = strlen(alphabet);
	for (i = 0; i < len; i++) {
		int chk = 0;
		for (j = 0; j < len2; j++) {
			if (str[i] == alphabet[j]) {
				chk = 1;
				stk.push(arr[j]);
			}
		}
		if (!chk) {
			if (str[i] == '+') {
				double b = stk.top();
				stk.pop();
				double a = stk.top();
				stk.pop();
				stk.push(a + b);
			}
			else if (str[i] == '*') {
				double b = stk.top();
				stk.pop();
				double a = stk.top();
				stk.pop();
				stk.push(a * b);
				
			}
			else if (str[i] == '/') {
				double b = stk.top();
				stk.pop();
				double a = stk.top();
				stk.pop();
				stk.push(a / b);

			}
			else {
				double b = stk.top();
				stk.pop();
				double a = stk.top();
				stk.pop();
				stk.push(a - b);
			}
		}
		//cout << stk.top() << endl;
	}
	//stk.pop();
	printf("%0.2f",stk.top());


	return 0;
}