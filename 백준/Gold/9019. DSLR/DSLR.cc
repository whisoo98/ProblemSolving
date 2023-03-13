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
int visit[10005];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int i, j;//for문변수-->가끔식 long으로
	int T; cin >> T;
	while (T--) {
		queue<pair<int, string>> q;
		int A, B;
		cin >> A >> B;
		q.push({ A, "" });
		visit[A] = 1;
		string answer;
		while (!q.empty()) {
			int now = q.front().first;
			string cmd = q.front().second;
			q.pop();
			if (now == B) {
				answer = cmd;
				break;
			}
			if (!visit[(now * 2) % 10000]) {
				q.push({ (now * 2) % 10000,cmd + "D" });
				visit[(now * 2) % 10000] = 1;
			}
			int tempa = now;
			int sum = 0;
			int arr[10];
			for (i = 3; i >= 0; i--) {
				//sum = (tempa % 10)*pow(10, i);
				arr[i] = tempa % 10;
				tempa /= 10;
			}
			//arr에 A 넣기
			/*int brr[10];
			brr[0] = arr[1];
			brr[1] = arr[2];
			brr[2] = arr[3];
			brr[3] = arr[0];
			for (i = 3; i >= 0; i--) {
				sum += brr[i] * pow(10, 3 - i);
			}*/
			//cout << sum << endl;
			//system.pause();
			sum = arr[1] * 1000 + arr[2] * 100 + arr[3] * 10 + arr[0];
			if (!visit[sum]) {
				q.push({ sum, cmd + "L" });
				visit[sum] = 1;
			}
			/*brr[0] = arr[3];
			brr[1] = arr[0];
			brr[2] = arr[1];
			brr[3] = arr[2];
			sum = 0;

			for (i = 3; i >= 0; i--) {
				sum += brr[i] * pow(10, 3 - i);
			}*/
			sum = arr[3] * 1000 + arr[0] * 100 + arr[1] * 10 + arr[2];
			if (!visit[sum]) {
				q.push({ sum,cmd + "R" });
				visit[sum] = 1;
			}

			if (now == 0 && !visit[9999]) {
				q.push({ 9999, cmd + "S" });
				visit[9999] = 1;
			}
			else if (!visit[now - 1]) {
				q.push({ now - 1,cmd + "S" });
				visit[now - 1] = 1;
			}
		}
		cout << answer << "\n";
		for (i = 0; i < 10000; i++) {
			visit[i] = 0;
		}
	}
	

	//for(i=0;i<n;i++) {}
	//for(i=0;i<n;i++) { for(j=0;j<n;j++) { } }

	return 0;
}