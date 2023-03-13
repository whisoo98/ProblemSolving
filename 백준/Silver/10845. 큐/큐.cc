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
#include<sstream>

using namespace std;

/*struct type_name {

}srt;*/

//vector <type> vec;
//stack <type> stk;
queue <int> q;
//string str;
//map <key_type,value_type> m;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int i, j;//for문변수-->가끔식 long으로
	int n;
	//scanf("%d", &n);
	cin >> n;
	while (n--) {
		//char command[20];
		//scanf("%s", command);
		string command;
		cin >> command;
		if (command == "push") {
			int a; cin >> a;
			//cout << "!" << a << endl;
			q.push(a);
		}
		else if (command == "pop") {
			if (q.empty()) printf("-1\n");
			else {
				printf("%d\n", q.front());
				q.pop();
			}
		}
		else if (command == "size") {
			printf("%d\n", q.size());
		}
		else if (command == "empty") {
			printf("%d\n", q.empty());
		}
		else if (command == "front") {
			if (q.empty()) printf("-1\n");
			else {
				printf("%d\n", q.front());
			}

		}
		else if (command == "back") {
			if (q.empty()) printf("-1\n");
			else {
				printf("%d\n", q.back());
			}

		}
	}

	return 0;
}