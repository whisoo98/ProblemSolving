#include <string>
#include <vector>
#include <queue>

#define ll long long
#define LIM 10'000'000
using namespace std;


// 홀수면 불가능
// 짝수만 가능
queue<int> q1,q2;

int preprocess(vector<int>& v1, vector<int>& v2){
    ll sum = 0;
    for(auto it : v1){
        q1.push(it);
        sum+=it;
    }
    for(auto it: v2){
        q2.push(it);
        sum+=it;
    }
    return sum%2;
}

ll makeSameQ(vector<int>& v1, vector<int>& v2){
    ll sum1 = 0;
    ll sum2 = 0;
    ll cnt = 0;
    for(auto it : v1){
        sum1+=it;
    }
    for(auto it: v2){
        sum2+=it;
    }
    while(sum1!=sum2 && cnt<=LIM){
        if(sum1>sum2){
            // pop q1
            int poped = q1.front();
            q1.pop();
            sum1-=poped;
            sum2+=poped;
            q2.push(poped);
        }
        else if (sum2>sum1){
            // pop q2
            int poped = q2.front();
            q2.pop();
            sum2-=poped;
            sum1+=poped;
            q1.push(poped);
        }
        cnt++;
    }
    if(cnt>LIM)
        return -1;
    return cnt;
}
int solution(vector<int> queue1, vector<int> queue2) {
    int is_odd = preprocess(queue1,queue2);
    if(is_odd){
        return -1;
    }
    return makeSameQ(queue1,queue2);
}