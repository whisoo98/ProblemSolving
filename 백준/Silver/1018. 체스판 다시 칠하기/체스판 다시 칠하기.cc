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


using namespace std;

/*struct type_name {

}srt;*/

//vector <type> vec;
//stack <type> stk;
//queue <type> q;
//string str;
//map <key_type,value_type> m;
char chess1[8][9] = {
	{ "WBWBWBWB" },
	{ "BWBWBWBW" },
	{ "WBWBWBWB" },
	{ "BWBWBWBW" },
	{ "WBWBWBWB" },
	{ "BWBWBWBW" },
	{ "WBWBWBWB" },
	{ "BWBWBWBW" },
};
char chess2[8][9] = {
	{ "BWBWBWBW" },
	{ "WBWBWBWB" },
	{ "BWBWBWBW" },
	{ "WBWBWBWB" },
	{ "BWBWBWBW" },
	{ "WBWBWBWB" },
	{ "BWBWBWBW" },
	{ "WBWBWBWB" }
};
char borad[55][55];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int i, j;//for문변수-->가끔식 long으로
	int y, x; scanf("%d %d ", &y, &x);


	for (i = 0; i < y; i++) {
		scanf("%s", borad[i]);
	}
	
	int m = 99;
	for (i = 0; i + 8 <= y; i++) {
		for (j = 0; j + 8 <= x; j++) {
			int chk1 = 0;
			int chk2 = 0;
			for (int ty = i; ty < i + 8; ty++) {
				for (int tx = j; tx < j + 8; tx++) {
					if (chess1[ty - i][tx - j] - borad[ty][tx]) chk1++;
					if (chess2[ty - i][tx - j] - borad[ty][tx]) chk2++;
					
				}
				

			}
			m = min(m, min(chk1, chk2));
		}
	}
	printf("%d", m);
	return 0;
}