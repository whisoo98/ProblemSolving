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
//queue <type> q;
//string str;
//map <key_type,value_type> m;
int arr_minus[55];
int arr_plus[55];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int i, j;//for문변수-->가끔식 long으로
	string minus = "-";
	//char plus = '+';
	string str;
	cin >> str;
	stringstream ss;
	ss << str;
	int num;
	int sum = 0;
	if (str[0] == minus[0]) {
		char giho;
		ss >> giho;
		while (ss.good()) {
			ss >> num >> giho;
			sum -= num;
		}
	}
	else {
		int swt = 1;
		char giho;
		int temp;
		ss >> temp;
		//cout << ss.good();
		sum += temp;
		
		while (ss.good()) {
			ss >> giho >> num;
			//cout << num<<endl;
			if (giho == minus[0]) swt = -1;
			//cout << ss.good() << endl;
			sum = sum + swt * num;
		}
	}
	cout << sum;
	return 0;
}