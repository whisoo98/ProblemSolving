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
long long comb[35][35] = { 1 , }; //xCy

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int i, j;//for문변수-->가끔식 long으로
	for (i = 0; i <= 30; i++) {
		comb[i][0] = 1;
		for (j = 1; j <= i; j++) {
			comb[i][j] = comb[i - 1][j - 1] + comb[i - 1][j];
		}
	}
	long long t, n, m;
	scanf("%lld", &t); 
	while (t--) {
		scanf("%lld %lld", &n, &m);
		printf("%lld\n", comb[m][n]);
	}

	return 0;
}