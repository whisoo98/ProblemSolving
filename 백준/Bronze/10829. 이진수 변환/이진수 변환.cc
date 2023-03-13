#include<stdio.h>
//이진수 교환 n을 이진수로 바꿈 %2로 해서 배열 저장하는걸 재귀함수이용
int arr[500];
int i = 0;
int bi(long long n) {
	if (n == 1) {
		arr[i] = 1;
		return 0; //처음에 1을 줄경우 아래 함수 에러남
	}
	long long temp;
	temp = n / 2;
	arr[i] = n % 2;
	i++;
	if (temp == 1) {//나중에 1일 경우 종료
		arr[i] = 1;
		return 0;
	}
	return bi(temp);
}
int main() {
	long long m;
	scanf("%lld", &m);
	bi(m);
	while (i >= 0) {
		printf("%d", arr[i]);
		i--;
	}


	return 0;
}