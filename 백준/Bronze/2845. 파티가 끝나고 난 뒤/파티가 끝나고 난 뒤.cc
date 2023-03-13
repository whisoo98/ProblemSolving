#include<stdio.h>

int main(){
    int a,b; scanf("%d %d",&a,&b);
    for(int i=1;i<=5;i++){
        int temp;
        scanf("%d ",&temp);
        printf("%d ",temp-a*b);
    }
}