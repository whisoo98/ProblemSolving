#include<cstdio>

int main(){
    
    int T;
    scanf("%d",&T);
    while(T--){
        int n,c;
        scanf("%d %d",&n,&c);
        if (!(n%c)) printf("%d\n",n/c);
        else printf("%d\n",n/c+1);
    }
    
    
    return 0;
}