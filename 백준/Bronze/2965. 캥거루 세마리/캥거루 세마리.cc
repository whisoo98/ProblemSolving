#include<cstdio>
#include<algorithm>

using namespace std;
int main(){
    
    int arr[3];
    scanf("%d %d %d",&arr[0],&arr[1],&arr[2]);
    sort(arr,arr+3);
    printf("%d",max(arr[2]-arr[1]-1,arr[1]-arr[0]-1));
    return 0;
    
}