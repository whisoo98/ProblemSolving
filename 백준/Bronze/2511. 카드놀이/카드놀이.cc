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
int arr[15];
int brr[15];
int aum, bum;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	char last = 'd';
	int i, j;//for문변수-->가끔식 long으로
	for (i = 1; i <= 10; i++) {
		cin >> arr[i];
	}
	for (i = 1; i <= 10; i++) {
		cin >> brr[i];
	}
	for (i = 1; i <= 10; i++) {
		if (arr[i] > brr[i]) {
			aum += 3;
			last = 'A';
		}
		else if (brr[i] > arr[i]) {
			bum += 3;
			last = 'B';
		}
		else {
			aum += 1;
			bum += 1;
		}
	}
	cout << aum << " " << bum << "\n";
	if (aum == bum) {
		if (last == 'd') {
			cout << "D";
		}
		else {
			cout << last;
		}
	}
	else if (aum > bum) {
		cout << "A";
	}
	else {
		cout << "B";

	}
	//for(i=0;i<n;i++) {}
	//for(i=0;i<n;i++) { for(j=0;j<n;j++) { } }

	return 0;
}