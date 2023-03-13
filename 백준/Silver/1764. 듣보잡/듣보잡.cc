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
#include<cstring>


using namespace std;

/*struct type_name {

}srt;*/


//stack <type> stk;
//queue <type> q;
//string str;
//map <key_type,value_type> m;

//string eme[500005];
//string emeqh[500005];
vector<string> eme;
vector<string> emeqh;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int i, j;//for문변수-->가끔식 long으로
	int n, m;
	int cnt = 0;
	scanf("%d %d", &n, &m);
	for (i = 0; i < n; i++) {
		//cin >> eme[i];
		char str[21];
	//	cin >> str;
		scanf("%s", str);
		eme.push_back(str);
		//cout << eme[i];
	}
	sort(eme.begin(), eme.end());

	for (i = 0; i < m; i++) {
		char str[21];
		//cin >> str;
		scanf("%s", str);
		/*for (j = n-cnt-1; j >=0; j--) {
			if (str == eme[j]) {
				emeqh.push_back( eme[j]);
				//eme[j] = "\0";
				eme.erase(eme.begin() + j);
				cnt++;
			}
		}*/
		int start = 0;
		int end = n -1;//-1??
		while (start <= end) {
			int mid = (start + end) / 2;
			/*if (str < eme[mid].c_str()) {
				end = mid-1;
			}*/
			if (strcmp(str, eme[mid].c_str()) < 0) {
				end = mid - 1;
			}
			else if (strcmp(str, eme[mid].c_str())==0) {
				emeqh.push_back(eme[mid]);
				cnt++;
				break;
				//eme.erase(eme.begin() + j);
			}
			else {
				start = mid + 1;
			}
		/*	if (start == end) {
				if (strcmp(str, eme[mid].c_str()) == 0) {
					emeqh.push_back(eme[mid]);
					cnt++;
					//eme.erase(eme.begin() + j);
				}
				break;
			}*/
		}
	
	}
	sort(emeqh.begin(), emeqh.end());
//	cout << cnt << "\n";
	printf("%d\n",cnt);
	for (i = 0; i < cnt; i++) printf("%s\n", emeqh[i].c_str());
	return 0;
}