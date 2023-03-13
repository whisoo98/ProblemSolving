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

vector<pair<int, int>> vec;// A , B
//queue <type> q;
//string str;
//map <key_type,value_type> m;
vector<int>v;
vector<int>Line;
int index[500005];
stack<int>stk;
/*int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int i, j;//for문변수-->가끔식 long으로
	int n;
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		int A, B;
		scanf("%d %d", &A, &B);
		vec.push_back({ A,B });
		//v.push_back(B);
	}
//	cout << vec.size();
	sort(vec.begin(), vec.end()); //페어A기준 정렬
	for (i = 0; i < n; i++) {
		v.push_back((vec.begin()+i)->second);
	}
	for (i = 0; i < n; i++) {
		int idx = lower_bound(Line.begin(), Line.end(), v[i]) - Line.begin();
		if (Line.size() > idx) {
			//Line.erase(Line.begin() + idx);
			//Line.insert(Line.begin() + idx, v[i]);
			Line[idx]=v[i];
			index[i] = idx;
		}
		else {
			Line.push_back(v[i]);
			index[i] = idx;
		}
	}
//	for (auto it = Line.begin(); it != Line.end(); it++) cout << *it << " ";
	printf("%d\n", n - Line.size());
	int size = Line.size();
	for (i = n-1; i >= 0; i--) {
		if (size - 1 == index[i]) {
			stk.push( v[i] );
			size--;
		}
	}
	for (i = 0; i < n; i++) {
		if (!stk.empty()){
			if (stk.top() != v[i]) {
				printf("%d\n", (vec.begin() + i)->first);
			}
			else {
				//	printf("%d\n", stk.top());
				stk.pop();
			}
		}
	}
	return 0;
}*/
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int i, j;//for문변수-->가끔식 long으로
	int n;
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		int A, B;
		scanf("%d %d", &A, &B);
		vec.push_back({ B,A });
		//v.push_back(B);
	}
	//	cout << vec.size();
	sort(vec.begin(), vec.end()); //페어A기준 정렬
	for (i = 0; i < n; i++) {
		v.push_back((vec.begin() + i)->second);
	}
	for (i = 0; i < n; i++) {
		int idx = lower_bound(Line.begin(), Line.end(), v[i]) - Line.begin();
		if (Line.size() > idx) {
			//Line.erase(Line.begin() + idx);
			//Line.insert(Line.begin() + idx, v[i]);
			Line[idx] = v[i];
			index[i] = idx;
		}
		else {
			Line.push_back(v[i]);
			index[i] = idx;
		}
	}
	//	for (auto it = Line.begin(); it != Line.end(); it++) cout << *it << " ";
	printf("%d\n", n - Line.size());
	int size = Line.size();
	for (i = n - 1; i >= 0; i--) {
		if (size - 1 == index[i]) {
//			stk.push(v[i]);
			v[i] = 987654321;
			size--;
		}
	}
	sort(v.begin(), v.end());
	for (i = 0; i < n - Line.size(); i++) printf("%d\n", v[i]);
	
	return 0;
}