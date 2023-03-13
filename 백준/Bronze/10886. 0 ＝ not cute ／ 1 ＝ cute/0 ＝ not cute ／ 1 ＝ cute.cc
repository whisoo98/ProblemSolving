#include<cstdio>

int main(){
    
    int i;
    int n;
    int sum1=0;
    int sum0=0;
    scanf("%d",&n);
    for(i=0;i<n;i++){
        int temp;
        scanf("%d",&temp);
        if(temp==1) sum1++;
        else sum0++;
    }
    if(sum1>sum0) printf("Junhee is cute!");
    else printf("Junhee is not cute!");
    
    return 0;
}