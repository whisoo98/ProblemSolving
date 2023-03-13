#include <iostream>
#include <algorithm>
#include <functional>

using namespace std;

int arr[10];
int sum;
int l, r;
int main() {
	// your code goes here
	for(int i=0;i<9;i++){
		scanf("%d",&arr[i]);
		sum += arr[i];
	}
	sort(arr,arr+9);
	l = 0, r = 8;
	while(l<=r){
		int temp = sum - arr[l] - arr[r];
		if(temp==100) break;
		if(temp>100) l++;
		else r--;
	}
	for(int i=0;i<9;i++){
		if(i==l || i==r) continue;
		printf("%d\n",arr[i]);
	}
	return 0;
}