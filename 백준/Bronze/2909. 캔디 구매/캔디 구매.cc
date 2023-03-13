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
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int i, j;//for문변수-->가끔식 long으로
	int price;
	int bill;
	cin >> price >> bill;
	if (bill == 0) {
		printf("%d", price);
		return 0;
	}
	int temp = 1;
	for (i = 0; i < bill; i++) {
		temp *= 10;
	}
	int realprice = price / temp;
	int rest = price % temp;
	if (0 <= rest && rest < temp / 2) printf("%d", realprice*temp);
	else printf("%d", realprice*temp + temp);

	return 0;
}