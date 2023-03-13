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
int arr0[100] = { 1, 0,  };
int arr1[100] = { 0, 1,  };


void fibo() {
	int i;
	for (i = 2; i <= 40; i++) {
		arr0[i] = arr0[i - 1] + arr0[i - 2];
		arr1[i] = arr1[i - 1] + arr1[i - 2];
	}

}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int i, j;//for문변수-->가끔식 long으로
	int n;
	cin >> n;
	fibo();

	while (n) {
		cin >> i;
		cout << arr0[i] << " " << arr1[i]<<endl;
		n--;
	}

	return 0;
}