#include <iostream>
#include <algorithm>
#include <functional>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <string>
#include <queue>
#include <stack>
#include <map>
#include <vector>
#include <set>
#include <sstream>
#include <ctime>
#include <climits>
#include <tuple>
#define N 500005
using namespace std;

int arr[N];
int brr[N];
int crr[N];
long long ans;

void merge(int left, int mid, int right) {
	int idx = left;
	int i = left, j = mid + 1;
	long long cnt = 0;
	while (i <= mid || j <= right) {
		if (i > mid) {
			brr[idx] = arr[j];
			idx++;
			j++;
			cnt++;
		}
		else if (j > right) {
			brr[idx] = arr[i];
			idx++;
			i++;
			ans += cnt;
		}
		else if (arr[i] <= arr[j]) {
			brr[idx] = arr[i];
			idx++;
			i++;
			ans += cnt;
		}
		else {
			brr[idx] = arr[j];
			idx++;
			j++;
			cnt++;
		}
	}
	for (i = left; i <= right; i++) arr[i] = brr[i];
}
void merge_sort(int left, int right) {
	int mid = (left + right) / 2;
	if (left < right) {
		merge_sort(left, mid);
		merge_sort(mid + 1, right);
		merge(left, mid, right);
	}
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int i, j; //for문 변수 -> longlong필요한지 확인
	int n; cin >> n;
	for (i = 1; i <= n; i++) {
		cin >> arr[i];
	//	brr[i] = arr[i];
	}
	merge_sort(1, n);
	cout << ans;
	return 0;
}