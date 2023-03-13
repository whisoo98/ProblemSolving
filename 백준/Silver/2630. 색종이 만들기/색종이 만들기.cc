#include <iostream>
using namespace std;


void Conquer(int n, int arr[150][150], int ans[5][5], int tmp[5][5], int tmp1[5][5], int flag){
	int W=0,B=0;
	for(int i=1;i<5;i++){
		W+=tmp[i][0];
		B+=tmp[i][1];
	}
	if(B==0 && W==4){
		W=1;
	}
	else if (B==4 && W==0){
		B=1;
	}
	tmp1[flag][0]=W;
	tmp1[flag][1]=B;
	ans[1][0]=W;
	ans[1][1]=B;
	//printf("W:%d B:%d\n",W,B);
}

void Divide(int n, int arr[150][150], int ans[5][5], int tmp1[5][5], int y, int x, int flag){
	if(n==1){
		if(arr[y][x]==0)
			tmp1[flag][0]=1;
		else tmp1[flag][1]=1;
	//	printf("y:%d x:%d\n",y,x);
	}
	else if(n>1) {
		int tmp[5][5];
		for(int i=0;i<5;i++){
			for(int j=0;j<5;j++){
				tmp[i][j]=0;
			}
		}
		Divide(n/2, arr, ans, tmp, y, x, 1);
		Divide(n/2, arr, ans, tmp, y, x+n/2, 2);
		Divide(n/2, arr, ans, tmp, y+n/2, x, 3);
		Divide(n/2, arr, ans, tmp, y+n/2, x+n/2, 4);
		Conquer(n, arr, ans, tmp, tmp1, flag);
		
	}
}

void Solution(int n, int arr[150][150]){
	int ans[5][5], tmp[5][5];
	Divide(n, arr, ans, tmp, 1, 1, 1);
	printf("%d\n%d",ans[1][0],ans[1][1]);
}

int arr[150][150];
int main() {
	// your code ges here
	int n; scanf("%d",&n);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			scanf("%d",&arr[i][j]);
		}
	}
	Solution(n,arr);
	return 0;
}