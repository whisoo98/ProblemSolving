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

int arr[105][105];
int brr[105][105];
int crr[105][105];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int i, j;//for문변수-->가끔식 long으로
	int n1, m1; cin >> n1 >> m1;
	for (i = 1; i <= n1; i++) {
		for (j = 1; j <= m1; j++) {
			cin >> arr[i][j];
		}
	}

	int n2, m2;
	cin >> n2 >> m2;
	for (i = 1; i <= n2; i++) {
		for (j = 1; j <= m2; j++) {
			cin >> brr[i][j];
		}
	}
	
	for (int k = 1; k <= n1; k++) {//3
		for (i = 1; i <= n2; i++) {//2
			for (j = 1; j <= m2; j++) {//3
				crr[k][j] += arr[k][i] * brr[i][j];
			}
		}
	}
	for (i = 1; i <= n1; i++) {
		for (j = 1; j <= m2; j++) {
			cout << crr[i][j] << " ";
		}
		cout << "\n";
	}
	//for(i=0;i<n;i++) {}
	//for(i=0;i<n;i++) { for(j=0;j<n;j++) { } }

	return 0;
}