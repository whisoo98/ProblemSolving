#include<stdio.h>
char s[101];
int main() {

	int i = 0, j;
	int alphabet[26];
	
	scanf("%s", s);
	for (j = 0; j < 26; j++) alphabet[j] = -1;

	while (s[i] != '\0') {
		for (j = 97; j < 123; j++)
			if (s[i] == j)
			{
				if (alphabet[j - 97] == -1) alphabet[j - 97] = i;
			}
		i++;
	}
	for (i = 0; i < 26; i++) {
		printf("%d ", alphabet[i]);
	}







	return 0;
}