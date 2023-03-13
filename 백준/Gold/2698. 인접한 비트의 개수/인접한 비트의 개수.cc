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
int arr[105][105][2];
	
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int i, j;//for문변수-->가끔식 long으로
	int T; cin >> T;
	arr[1][0][0] = 1;
	arr[1][0][1] = 1;
	for (i = 2; i <= 100; i++) {
		for (j = 0; j < i; j++) {
			if (j == 0) {
				arr[i][j][0] = arr[i - 1][j][0] + arr[i - 1][j][1];
				arr[i][j][1] = arr[i - 1][j][0];
				arr[i][j + 1][1] = arr[i - 1][j][1];
			}
			else {
				arr[i][j][0] += arr[i - 1][j][0] + arr[i - 1][j][1];
				arr[i][j][1] += arr[i - 1][j][0];
				arr[i][j + 1][1] = arr[i - 1][j][1];
			}
			//cout << i << " " << j << " " << arr[i][j][0] + arr[i][j][1] << "\n";
		}
	}
	while (T--) {
		int n, k;
		cin >> n >> k;
		cout << arr[n][k][0] + arr[n][k][1]<<"\n";
	}

	//for(i=0;i<n;i++) {}
	//for(i=0;i<n;i++) { for(j=0;j<n;j++) { } }

	return 0;
}