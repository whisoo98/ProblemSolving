#include <iostream>
#define ll long long
#define MOD 1000
using namespace std;

void Conquer(int arr[10][10], int ans[10][10], int crr[10][10], int drr[10][10], int temp[10][10], int n, ll b){
	
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			temp[i][j]=0;
			for(int k =0;k<n;k++){
				temp[i][j]+=((crr[i][k]%MOD)*(drr[k][j]%MOD))%MOD;
			}
			temp[i][j]%=MOD;
			//printf("%d ",brr[i][j]);
			ans[i][j]=temp[i][j];
		}
		
	}
	
}

void Divide(int arr[10][10], int ans[10][10], int temp[10][10], int n, ll b){
	if(b==1) {
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				temp[i][j]=arr[i][j]%MOD;
			}
		}
		return;
	}
	//int (*crr)[10];
	//int (*drr)[10];
	//int temp[10][10];
	int crr[10][10];
	int drr[10][10];
	if(b%2){
		Divide(arr,ans,crr,n,b/2);
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				drr[i][j]=0;
				for(int k=0;k<n;k++){
					drr[i][j]+=((crr[i][k]%MOD)*(arr[k][j])%MOD)%MOD;
				}
				drr[i][j]%=MOD;
			}
		}
		Conquer(arr, ans, crr, drr, temp, n, b);
	}
	else{
		Divide(arr,ans,crr,n,b/2);
		Conquer(arr, ans, crr, crr, temp, n, b);
	}
	
}

void Solution(int arr[10][10], int ans[10][10], int temp[10][10], int n, ll b){
	//ans = Divide(arr,ans,n,b);
	Divide(arr,ans,temp,n,b);
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			printf("%d ",ans[i][j]%MOD);
		}
		printf("\n");
	}
}

int arr[10][10];
int ans[10][10];
int temp[10][10];

int main() {
	// your code goes here
	int n; ll b; scanf("%d %lld",&n,&b);
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			scanf("%d",&arr[i][j]);
			ans[i][j]=arr[i][j];
		}
	}
	Solution(arr,ans,temp,n,b);
	return 0;
}