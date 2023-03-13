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
int combination[20][20];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int i, j;//for문변수-->가끔식 long으로
	int y, x, k;
	cin >> y >> x >> k;
	combination[0][0] = 1;
	combination[1][0] = 1;
	combination[1][1] = 1;
	for (i = 2; i <= 15; i++) {
		for (j = 0; j <= i; j++) {
			if (j == 0) combination[i][j] = 1;
			else if (j == i) combination[i][j] = 1;
			else combination[i][j] = combination[i - 1][j - 1] + combination[i - 1][j];
		}
	}
	/*for (i = 0; i <= 15; i++) {
		for (j = 0; j <= i; j++) {
			cout << "combination[" << i << "][" << j << "]:" << combination[i][j] << endl;
		}
	}*/
	if (!k) {
		cout << combination[x + y - 2][x - 1];
	}
	else {
		int q = k / x;//세로
		int rest = k-q*x;//가로
		cout << combination[q + rest - 1][q] * combination[y - 1 - q + x - 1 - (rest - 1)][y - 1 - q]<<endl;
		//cout << combination[q + rest - 1][q] << endl;
		//cout << combination[y - 1 - q + x - 1 - (rest - 1)][y - 1 - q] << endl;
	}
	return 0;
}