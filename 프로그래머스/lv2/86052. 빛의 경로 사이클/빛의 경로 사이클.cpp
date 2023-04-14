#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;
int arr[505][505][4];
int dy[]={-1,0,1,0};
int dx[]={0,-1,0,1};
int y, x;

void rayTrace(int i,int j, int dir, int cnt, vector<string>& grid,vector<int>& answer){
    int ty = i + dy[dir];
    int tx = j + dx[dir];
    if(ty<0) ty = y-1;
    if(ty>=y) ty = 0;
    if(tx<0) tx = x-1;
    if(tx>=x) tx = 0;
    
    if(grid[ty][tx]=='S'){
        dir = dir;
    }
    else if(grid[ty][tx]=='L'){
        
        dir--;
        dir=(dir+4)%4;
    }
    else{
        dir++;
        dir %=4;
    }
    
    if(arr[ty][tx][dir]==1){
        //return cnt;
        answer.push_back(cnt);
        return;
    }
    arr[ty][tx][dir]=1;
    
    rayTrace(ty,tx,dir,cnt+1,grid,answer);

}

vector<int> solution(vector<string> grid) {
    // vector<string>input;
    // input.push_back("RR");
    // input.push_back("RR");
    // grid = input;
    vector<int> answer;
    y= grid.size();
    x= grid[0].size();
    
    for(int i=0;i<y;i++){
        for(int j =0;j<x;j++){
            for(int dir = 0; dir<4; dir++){
                if(arr[i][j][dir]==0){
                    // cout<<i<<" " <<j<<endl;
                    arr[i][j][dir]=1;
                    // int temp = rayTrace(i,j,dir, 1,grid);
                    rayTrace(i,j,dir, 1,grid,answer);
                    // if(temp!=0){
                    //     answer.push_back(temp);
                    // }
                }
            }
        }
    }
    sort(answer.begin(),answer.end());
    return answer;
}