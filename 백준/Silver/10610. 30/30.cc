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
long long arr[10];
char s[11] = "0123456789";
string temp;

//map <key_type,value_type> m;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int i, j;//for문변수-->가끔식 long으로
	string n;
	//cin >> n;
	/*while (n) {
		int temp = n % 10;
		cout << temp << endl;
		arr[temp]++;
		n /= 10;
	}*/
	char c='\0';
	while (1) {
		scanf("%c", &c);
		if (c == '\n') break;
		for (i = 0; i < 10; i++) {
			if (s[i] == c) {
				arr[i]++;
			}
		}
	}
	//cout << "!";
	/*for (auto it = n.begin(); it != n.end(); it++) {
		for (i = 0; i < 10; i++) {
			if (s[i] == *it) {
				arr[i]++;
			}
		}
	}*/
	if (arr[0] == 0) {
		printf("-1");
		return 0;
	}
	long long sum = 0;
	for (i = 1; i < 10; i++) {
//		cout << "arr["<<i<<"]"<<arr[i] << endl;
		sum += arr[i] * i;
	}
	//j = 1;
//	cout << sum<<endl;
	if (sum % 3 == 0) {
		for (i = 9; i >=0; i--) {
			while (arr[i]) {//뒤에 0을 못붙임
				//temp = temp + s[i];
				//j *= 10;
				//arr[i]--;
				printf("%c", s[i]);
				arr[i]--;
			}
		}
	}
	else {
		printf("-1");
		return 0;
	}
	/*while (arr[0]) {
		temp *= 10;
		arr[0]--;
	}*/
//	cout << temp;
	return 0;
}