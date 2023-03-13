#include<stdio.h>
#include<algorithm>
#include<functional>

using namespace std;

int arr[45];
int main(){

    for(int i=0;i<10;i++){
        int a; scanf("%d",&a);
        arr[a%42]++;
    }
    sort(arr,arr+45,greater<int>());
    int chk=0;
    for(int i=0;i<45;i++){
        if(arr[i]) chk++;
    }
    printf("%d",chk);
}