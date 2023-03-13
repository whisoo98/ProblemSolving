#include<stdio.h>
#include<string.h>
/*ASCII CODE
a=97 z=122; A=65 Z=90;
*/
//코드 개요 -- 소문자 대문자 나눠서 모두 대입
char str[1000005];//단어 받을 배열
int alphabet[26];//알파벳 횟수 카운팅;
int main() {
	//int i, j, num, temp, max = -1;
	int i,j;//for 변수
	int	num;//배열번호
    int max=-1;//최대찾기
	int temp;//max가 여러개인지 체크
	scanf("%s", str);
    int len = strlen(str);
	for (i = 0; i < len; i++) {
		for (j = 0; j < 26; j++) {
			if (str[i] == j + 65) {//대문자에 대하여
				alphabet[j]++;
				break;
			}
			else if (str[i] == j + 97) {//소문자에 대하여
				alphabet[j]++;
				break;
			}			
		}
	}
	for (i = 0; i < 26; i++) {
		if (alphabet[i] >= max) {//치환기
			temp = max;
			max = alphabet[i];
			num = i;
			
		}
	}
	if (max == temp) printf("?");
	else printf("%c", num + 65);
	return 0;
}