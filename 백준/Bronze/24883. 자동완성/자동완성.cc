#include<iostream>


using namespace std;


void Solution(char a){
    if(a=='N'||a=='n') cout<<"Naver D2"<<"\n";
    else cout<<"Naver Whale"<<"\n";
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    char a; cin>>a;
    Solution(a);
    return 0;
}