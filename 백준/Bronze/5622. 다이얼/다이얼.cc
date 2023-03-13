#include<stdio.h>
#include<string>
#include<iostream>
//1을 걸려면 2초 +1마다 1초 추가 알파벳암기
/*abc2 def3 ghi4 jkl5 mno6 pqrs7 tuv8 wxyz9*/
using namespace std;
//2~15글자 대문자 입력받아
//필요한 시간출력
//코딩개요--2차원 문자열배열을 이용하여 각 배열에 알파벳을 저장, 배열[i][j]에 대해서 맞는 지 검사

int i, j,k;//for 변수
int chk;//체커
char alphabet[8][4] = { {'A','B','C',}, {'D','E','F',}, {'G','H','I',}, {'J','K','L',}, {'M','N','O',}, {'P','Q','R','S'}, {'T','U','V',}, {'W','X','Y','Z'} };
int time;//시간 길이 체크;
int T;//sum of time;
int main() {
	
	string s;
	getline(cin, s);
	//printf("%d", s.size());
	
	for (i = 0; i < s.size(); i++) {
		time = 3;
		for (j = 0; j < 8; j++) {
			for (k = 0; k < 4; k++) {
				if (s[i] == alphabet[j][k]) {
					time=time+j;
					T = T + time;
					break;
				}
			}
			if (time != 3) break;
		}
	}
	printf("%d", T);

	return 0;
}