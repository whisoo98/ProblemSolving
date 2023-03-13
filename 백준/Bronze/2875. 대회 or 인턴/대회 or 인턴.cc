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
	int n, m, k;//여 남 인턴
	scanf("%d %d %d", &n, &m, &k);
	int qn = n / 2;
	int rn = n % 2;
	k = k - rn;
	if (qn > m) {
		int temp = qn - m;
		k = k - 2 * temp;
		qn = m;
	}
	else if (qn == m) {

	}
	else {
		int temp = m - qn;
		k = k - temp;
		m = qn;
	}
	//qn == m;
	while (k > 0) {
		k -= 3;
		qn--;
		m--;
	}
	printf("%d", m);
	return 0;
}