#include<stdio.h>
#include<string.h>
char ox[80];

int main() {

	int test;//test case 의 갯수
	int chk=0;//연속 체크
	int i, j;//for 변수
	int o = 'O';//O판단
	int x = 'X';//X판단
	int score=0;//점수
	scanf("%d", &test);

	for (i = 0; i < test; i++) {
		scanf("%s", ox);
		for (j = 0; j < strlen(ox); j++) {
			if (ox[j] == o) {
				chk++;
				score = score + chk;
			}
			else chk = 0;
		}
		printf("%d\n", score);
		score = 0;
		chk = 0;
	}

	return 0;
}