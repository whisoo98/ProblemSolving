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
#define dif 0.0001
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int i, j;//for문변수-->가끔식 long으로
	int T; cin >> T;
	while (T--) {
		double A, B, target;
		char channel;
		cin >> A >> B >> channel >> target;
		if (target == A || target == B) {
			if (target == A && target == B) {
				cout << "0\n";
			}
			else if (target == A) {
				if (channel == 'A') cout << "0\n";
				else cout << "1\n";
			}
			else {
				if (target == B) {
					if (channel == 'B') cout << "0\n";
					else cout << "1\n";
				}
			}
		}

		else {
			int cnt_a = 0, cnt_b = 0, cnt = 10;
			double temp = A;
			for (i = 1; i <= 6; i++) {
				temp += 0.02;
				if (temp >= 146.001) temp = 144.000;
				cnt_a++;
				if (abs(temp - target) < dif) break;
			}
			cnt = cnt_a;
			cnt_a = 0;
			temp = A;
			for (i = 1; i <= 6; i++) {
				temp -= 0.02;
				if (temp <= 143.999) temp = 146.000;
				cnt_a++;
				if (abs(temp - target) < dif) break;
			}
			cnt = min(cnt, cnt_a);

			cnt_a = cnt;

			temp = B;
			for (i = 1; i <= 6; i++) {
				temp += 0.02;
				if (temp >= 146.001) temp = 144.000;
				cnt_b++;
				if (abs(temp - target) < dif) break;
			}
			cnt = cnt_b;
			cnt_b = 0;
			temp = B;
			for (i = 1; i <= 6; i++) {
				temp -= 0.02;
				if (temp <=143.999 ) temp = 146.000;
				cnt_b++;
				//cout << temp << endl;
				if (abs(temp - target) < dif) break;
			}
			//cout << cnt_b << endl;
			cnt = min(cnt, cnt_b);

			cnt_b = cnt;

			if (channel == 'A') {
			//	cout << cnt_a << " " << cnt_b << endl;
				cnt = min(cnt_a, cnt_b + 1);
				cnt = min(cnt, 6);
			}
			else {
				cnt = min(cnt_a + 1, cnt_b);
				cnt = min(cnt, 6);
			}
			cout << cnt << "\n";
		}
	}
	//for(i=0;i<n;i++) {}
	//for(i=0;i<n;i++) { for(j=0;j<n;j++) { } }

	return 0;
}