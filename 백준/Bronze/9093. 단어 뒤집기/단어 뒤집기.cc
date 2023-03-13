#include<stdio.h>
#include<cstring>
#include<string>
#include<iostream>
#include<sstream>    
using namespace std;
int main(){
    int n; scanf("%d ",&n);
    while(n--){
        string s;
        getline(cin,s);
        char c;
        //scanf("%c",&c);
        //cout<<s;
        //char *ptr = strtok(s.c_str());
        stringstream ss(s);
        string temp;
        ss>>temp;
        while(ss.good()){
            int len = temp.length();
            for(int i =0;i<len;i++){
                printf("%c",temp[len-1-i]);
            }
            printf(" ");
            ss>>temp;
        }
        int len = temp.length();
            for(int i =0;i<len;i++){
                printf("%c",temp[len-1-i]);
            }
            printf(" ");
        printf("\n");
    }
    return 0;
}