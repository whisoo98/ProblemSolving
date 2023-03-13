#include <iostream>
#include <cstring>
#include <sstream>
using namespace std;



void Solution(string s){
	stringstream ss; ss<<s;
	int arr[55];
	int sum[55];
	for(int i=0;i<55;i++) sum[i]=0;
	int t =0;
	char cmd[55];
	int n = 0;
	while(ss.good()){
		ss>>arr[n]>>cmd[n];
		sum[t]+=arr[n];
		if(cmd[n]=='-') t++;
		n++;
	}
	int SUM=sum[0];
	for(int i=1;i<=t;i++){
		SUM-=sum[i];
	}
	cout<<SUM<<"\n";
}
int main() {
	// your code goes here
	string s; getline(cin,s);
	Solution(s);
	return 0;
}