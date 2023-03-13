#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

long long divide(long long n, long long cnt, long long div) {
   long long tmp;
   if (cnt > 1) tmp = divide(n, cnt / 2, div) % div;

   if (cnt == 1) return n;
   else if (cnt % 2 == 0) {
      return (tmp%div*tmp%div)%div;
   }
   else if (cnt % 2 == 1) {
      return (tmp%div*tmp%div*n%div)%div;
   }
}

int main() {
   long long n, cnt, div;
   cin >> n >> cnt >> div;
   cout << divide(n, cnt, div)%div << "\n";
}