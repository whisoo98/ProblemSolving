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
/*도현이네 반 학생 N명의 이름과 국어, 영어, 수학 점수가 주어진다. 이 때, 다음과 같은 조건으로 학생의 성적을 정렬하는 프로그램을 작성하시오.

국어 점수가 감소하는 순서로
국어 점수가 같으면 영어 점수가 증가하는 순서로
국어 점수와 영어 점수가 같으면 수학 점수가 감소하는 순서로
모든 점수가 같으면 이름이 사전 순으로 증가하는 순서로 (단, 아스키 코드에서 대문자는 소문자보다 작으므로 사전순으로 앞에 온다.)*/
// 국어 내림차순 영어 오름차순 수학 내림차순 이름 이름 오름차순

using namespace std;

struct score {
	string s;
	int kor;
	int eng;
	int math;
}srt;

vector <score> vec;
//stack <type> stk;
//queue <type> q;
//string <type> str;
bool cmp(score a, score b)
{
//	cout << "1\n";
	if ( a.kor > b.kor ) return true;
	else if ( a.kor == b.kor )
	{
//		cout << "2\n";
		if ( a.eng < b.eng ) return true;
		else if ( a.eng == b.eng )
		{
//			cout << "3\n";
			if ( a.math > b.math ) return true;
			else if ( a.math == b.math )
			{
//				cout << "4\n";
				if ( a.s < b.s ) return true;
				return false;
			}
			return false;
		}
		return false;
	}
	return false;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int i, j;//for문변수-->가끔식 long으로
	int n;
	cin >> n;
	int temp = n;
	while ( n>0 )
	{
		cin >> srt.s >> srt.kor >> srt.eng >> srt.math;
		vec.push_back(srt);
		//cout << vec[12 - n].s << vec[12 - n].kor << vec[12 - n].eng << vec[12 - n].math << '\n';
		n--;
	}

	sort(vec.begin(), vec.end(), cmp);

	while ( n<temp )
	{
		cout << vec[n].s<<'\n';
		n++;
	}
	return 0;
}