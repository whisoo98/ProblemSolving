#include <iostream>
#include <algorithm>
#include <functional>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <string>
#include <queue>
#include <stack>
#include <map>
#include <vector>
#include <set>
#include <sstream>
#include <ctime>
#include <climits>
#include <tuple>
#define N 
#define ll long long
#define endl "\n"
#define MID(a,b) (a+b)/2

using namespace std;

map<string, double> grades;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	grades["A+"] = 4.5;
	grades["A0"] = 4.0;
	grades["B+"] = 3.5;
	grades["B0"] = 3.0;
	grades["C+"] = 2.5;
	grades["C0"] = 2.0;
	grades["D+"] = 1.5;
	grades["D0"] = 1.0;
	grades["F"] = 0.0;
	int i, j; //for문 변수 -> longlong필요한지 확인
	int tot_score = 0;
	double tot_grade = 0;
	for (int i = 0; i < 20; i++) {
		string name; cin >> name;
		double score; cin >> score;
		tot_score += (int)score;
		string grade; cin >> grade;
		if (grade == "P") {
			tot_score -= (int)score;
			continue;
		}
		tot_grade += grades[grade] * score;
	}
	cout << tot_grade / tot_score << endl;;
	return 0;
}