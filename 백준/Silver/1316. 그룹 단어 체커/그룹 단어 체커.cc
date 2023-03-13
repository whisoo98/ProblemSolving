#include<stdio.h>
#include<string.h>
/*가능한 경우
1. 처음에 반복이 존재  aaa
2. 처음에 반복x 그 이후 반복 존재 avdddd
3. 한문자 그대로 aaaaaaaaaaaaaaaa
4.
*/

/*/코딩 개요-->입력받은 즉시 탐색
1. i번째와 i+1번째가 같은지를 먼저 확인
case 1: 같지않음 - i번째를 기준으로 이후에 같은 거 있는지 확인 있으면 제외, 없으면 i+1을 기준으로 1번 다시
case 2: 같다 - 1번으로 돌아감
*/


char word[100];//단어받음
int num; //받는 개수 체크
int i, j,k;//for 변수
int chk; //체커
int change;//스위칭변수
int temp;//배열번호 간이변수

int main() {
	
	scanf("%d", &num);
	
	for (i = 0; i < num; i++) {
		scanf("%s", word);
		change = 0;
		for (j = 0; j < strlen(word); j++) {
			if (word[j] != word[j + 1]) {
				for (k = j; k < strlen(word); k++) {
					if (word[j] == word[k + 1]) change++;
				}
			}
			if (change != 0) break;
		}
		if (change == 0) chk++;

	}

	printf("%d", chk);
	return 0;
}