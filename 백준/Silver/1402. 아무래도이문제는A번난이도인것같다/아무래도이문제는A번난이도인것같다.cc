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
#include<cmath>

using namespace std;

/*struct type_name {

}srt;*/

//vector <type> vec;
//stack <type> stk;
//queue <type> q;
//string str;
//map <key_type,value_type> m;
//////////6보다 큰 합성수는 무조건 6으로 변할 수 있고 이 6은 무조건 5가될수있다.
///->소수일경우
///->0일경우
///->음수일경우

///결론적으로 a,b에 대해서
///a가 양의 홀수이면 a= -1*-1 .... *1*a로 만들어서 0을 만든후에 b로 만들수 잇음 -> 0 =  b*0;
//->이건 b의 부호와 관계 없다.
//a가 음의 홀수이면 a = -1 * c -> a' = 어떤 양의 짝수 -> a''은 양의 홀수로 만들수 있다.
//a가 홀수이면 ㅇㅋ;

///a가 짝수이면?
//->이건 양의 정수쪽에서(0포함)
//a가 음의 짝수

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int i, j;//for문변수-->가끔식 long으로
	int T;
	cin >> T;
	while (T) {
		printf("yes\n");
		T--;
	}

	return 0;
}