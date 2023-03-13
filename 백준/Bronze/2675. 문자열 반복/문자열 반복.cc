#include<stdio.h>
#include<string.h>
char s[21];
char str[1000];
int main() {

	int i , j,k;
	int test;
	int replay[1000];
	
	scanf("%d", &test);
	for (k= 0; k < test; k++) {
		scanf("%d %s", &replay[k], s);
		for (i = 0; i < strlen(s); i++) {
			for (j = 0; j < replay[k]; j++) {
				str[j] = s[i];
				printf("%c", str[j]);
				//str[j] = '\0';
			}
		}
		printf("\n");
		//for (i = 0; i < 21; i++) s[i] = '\0';
	}


	return 0;
}