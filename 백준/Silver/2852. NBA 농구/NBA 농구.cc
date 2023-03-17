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

#define N 105
#define ll long long
#define endl "\n"
#define MID(a,b) (a+b)/2

using namespace std;


int last[5];
int score[5];
int firstA;
int firstB;
int lastA;
int lastB;
int scoreA;
int scoreB;
int timeA;
int timeB;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, j; //for문 변수 -> longlong필요한지 확인
	int n; scanf("%d", &n);
	int flag = 0;
	for (int i = 0; i < n; i++) {
		int team; int m, s;
		scanf("%d %d:%d", &team, &m, &s);
		if (team == 1) {
			scoreA++;
			lastA = m * 60 + s;
			if (flag == 0 && scoreA > scoreB) {
				flag = 1;
				firstA = lastA;
			}
		}
		else {
			scoreB++;
			lastB = m * 60 + s;
			if (flag == 0 && scoreA < scoreB) {
				flag = 2;
				firstB = lastB;

			}
		}
		if (scoreA == scoreB) {
			if (flag == 1) {
				timeA += abs(firstA - lastB);
				flag = 0;
			}
			else if(flag==2){
				flag = 0;
				timeB += abs(firstB - lastA);
			}
		}
	}
	if (flag == 1) {
		timeA += 48 * 60 - firstA;
		flag = 0;
	}
	else if(flag==2){
		flag = 0;
		timeB += 48 * 60 - firstB;
	}

	if (timeA / 60 < 10) {
		printf("0");
	}
	printf("%d:", timeA / 60);
	if (timeA % 60 < 10) {
		printf("0");
	}
	printf("%d\n", timeA % 60);

	if (timeB / 60 < 10) {
		printf("0");
	}
	printf("%d:", timeB / 60);
	if (timeB % 60 < 10) {
		printf("0");
	}
	printf("%d\n", timeB % 60);
	return 0;
}