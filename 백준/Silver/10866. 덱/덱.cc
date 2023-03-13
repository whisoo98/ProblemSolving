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
#include<deque>
#include<sstream>
using namespace std;

/*struct type_name {

}srt;*/

//vector <type> vec;
//stack <type> stk;
//queue <type> q;
//string str;
//map <key_type,value_type> m;

deque<int> deq;
/*push_front X: 정수 X를 덱의 앞에 넣는다.
push_back X: 정수 X를 덱의 뒤에 넣는다.
pop_front: 덱의 가장 앞에 있는 수를 빼고, 그 수를 출력한다. 만약, 덱에 들어있는 정수가 없는 경우에는 -1을 출력한다.
pop_back: 덱의 가장 뒤에 있는 수를 빼고, 그 수를 출력한다. 만약, 덱에 들어있는 정수가 없는 경우에는 -1을 출력한다.
size: 덱에 들어있는 정수의 개수를 출력한다.
empty: 덱이 비어있으면 1을, 아니면 0을 출력한다.
front: 덱의 가장 앞에 있는 정수를 출력한다. 만약 덱에 들어있는 정수가 없는 경우에는 -1을 출력한다.
back: 덱의 가장 뒤에 있는 정수를 출력한다. 만약 덱에 들어있는 정수가 없는 경우에는 -1을 출력한다.*/

string command[8] = { "push_front","push_back","pop_front","pop_back","size","empty","front","back" };
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int i, j;//for문변수-->가끔식 long으로
	int n;
	cin >> n;
	while (n--) {
		string str;
		cin >> str;
		for (i = 0; i < 8; i++) {
			if (str == command[i]) break;
		}
		switch (i)
		{
		case 0:
			int num;
			cin >> num;
			deq.push_front(num);
			break;
		case 1:
			cin >> num;
			deq.push_back(num);
			break;
		case 2:
			if (!deq.empty()) {
				cout << deq.front() << "\n";
				deq.pop_front();
			}
			else cout << "-1\n";
			break;
		case 3:
			if (!deq.empty()) {
				cout << deq.back() << "\n";
				deq.pop_back();
			}
			else cout << "-1\n";
			break;
		case 4:
			cout << deq.size()<<"\n";
			break;
		case 5:
			cout << deq.empty()<<"\n";
			break;
		case 6:
			if (!deq.empty()) cout << deq.front()<<"\n";
			else cout << "-1\n";
			break;
		case 7:
			if (!deq.empty()) cout << deq.back()<<"\n";
			else cout << "-1\n";
			break;
		}
	}

	return 0;
}