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
int arr[1005];
void era(){
	int i, j;
	for (i = 2; i < 1001; i++) arr[i] = 1;
	for (i = 2; i < 1001; i++) {
		for (j = i * i; j < 1001; j +=i) {
			if (arr[j] != 0) arr[j]=0;
			else continue;
		}
	}
}

int main()
{
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL);
//	cout.tie(NULL);
	int i, j;//for문변수-->가끔식 long으로
	int n;
	scanf("%d", &n);
	era();
	int chk = 0;
	int temp;
	for (i = 0; i < n; i++) {
		scanf("%d", &temp);	
		if (arr[temp]) chk++;
	}

	printf("%d", chk);

	
	return 0;
}