#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>
#define H 0
#define C 1
#define O 2
using namespace std;


void Recursive(int arr[5], string s, int idx, int* ret, int* jump_idx){
	int len = s.size();
	int temp=0,sum=0;
	for(int i = idx; i < len; i++){
		if( s[i] == '('){
			sum+=temp;
			int ret2, jump_idx2;
			Recursive(arr, s, i+1, &ret2, &jump_idx2);
			temp = ret2;
			//printf("temp : %d\n",temp);
			i = jump_idx2;
		}
		else if ( s[i] == ')'){
			*jump_idx = i;
			sum+=temp;
			*ret = sum;
			//printf("sum : %d\n",sum);
			return;
		}
		else{
			if(s[i]=='H' || s[i]=='C' || s[i]=='O'){
				//cout<<s[i]<<endl;
				sum+=temp;
				if(s[i]=='H'){
					temp = arr[H];
				}
				else if(s[i]=='C'){
					temp = arr[C];
				}
				if(s[i]=='O'){
					temp = arr[O];
				}
			}
			else{//number
				sum+=temp*atoi(s.substr(i,1).c_str());
				//printf("atoi(s.substr(i,1).c_str()) : %d\n",atoi(s.substr(i,1).c_str()));
				temp=0;
			}
		}
	}
	sum+=temp;
	*ret = sum;
	//printf("aaaa%d\n",sum);
}

void Solution(int arr[5], string s){
	int idx=0, ret=0, jump_idx;
	Recursive(arr, s, idx, &ret, &jump_idx);
	printf("%d",ret);
}

int arr[5]={1,12,16};

int main() {
	// your code goes here
	string s, ss;
	cin>>s;
	//ss = "("+s+")";
	ss=s;
	Solution(arr,ss);
	return 0;
}