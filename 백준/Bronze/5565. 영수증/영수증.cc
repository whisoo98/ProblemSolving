#include<cstdio>

int main(){
    
    int sum;
    int temp;
    scanf("%d",&sum);
    int i;
    for(i=1;i<=9;i++){
        scanf("%d",&temp);
        sum =sum-temp;
    }
    printf("%d",sum);
    
    return 0;
}