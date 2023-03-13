#include<cstdio>

int dp[50][50];

int main(){
    int n,k; scanf("%d %d",&n,&k);
    int i,j;
    dp[0][0]=1;
    dp[1][0]=1;
    dp[1][1]=1;
    for(i=2;i<=10;i++){
        for(j=0;j<=i;j++){
           if(j==0 || j==i){
               dp[i][j]=1;
           }
            else{
                dp[i][j]=dp[i-1][j-1]+dp[i-1][j];
            }
        }
    }
    printf("%d",dp[n][k]);
    return 0;
}