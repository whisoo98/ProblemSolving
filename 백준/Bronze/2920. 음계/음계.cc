#include<stdio.h>

int main() {

	int i=0;
	int melody[8];
	int chk = 0;
	while (i < 8) {
		scanf("%d", &melody[i]);
		i++;
	}
	i = 0;
	while (i < 7) {
		if (melody[i] + 1 == melody[i + 1]) chk++;
		else if (melody[i] + -1 == melody[i + 1]) chk--;
		else break;
		i++;
	}
	if (chk == 7) printf("ascending");
	else if (chk == -7) printf("descending");
	else printf("mixed");
	return 0;
}