#include <iostream>
#include <algorithm>
using namespace std;



void Solution(int arr[1005], int n){
	int swt=0;
	int low=0, high=0;
	int diff = 0;
	for(int i =1;i<=n;i++){
		if(arr[i]>arr[i-1]){
			if(swt==1){
				high = arr[i];
			}
			else{
				swt=1;
				low = arr[i-1];
				high = arr[i];
			}
		}
		else if(swt==1){
			high = arr[i-1];
			diff = max(diff, high-low);
			swt =0;
		}
	}
	printf("%d\n",diff);
}


int arr[1005];
int main() {
	// your co goes here
	int n ; scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&arr[i]);	
	}
	Solution(arr,n);
	return 0;
}