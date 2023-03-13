#include <stdio.h>
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <functional>
#include <stdlib.h>
#include <string>
#include <queue>
#include <stack>
#include <map>


using namespace std;

int arr[200005];
//int sum[100005];

/*struct type_name {

}srt;*/

//vector <type> vec;
//stack <type> stk;
//queue <type> q;
//string str;
//map <key_type,value_type> m;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int i, j;//for문변수-->가끔식 long으로

	int T;
	cin >> T;
	while ( T )
	{
		int n, m, k;
		int chk = 0;
		
		cin >> n >> m >> k;//n은 집의수 m은 훔칠 집의수 k는 한계치; k-1까지가 끝임
		for ( i = 0; i < n; i++ )
		{
			cin >> arr[i];
		}
		if ( n != m )
		{
			for ( i = 0; i < m - 1; i++ )
			{
				arr[n + i] = arr[i];
			}
			/*	for ( i = 0; i < n; i++ )
				{
					int sum = 0;
					for ( j = 0; j <  m; j++ )
					{
						sum = sum + arr[i+j];
					}
					if ( sum < k ) chk++;
				}*/

				//sum 초기값
			int sum = 0;
			for ( i = 0; i < m; i++ ) sum += arr[i];
			if ( sum < k ) chk++;
			for ( i = m; i < n + m - 1; i++ )
			{
				sum = sum - arr[i - m] + arr[i];
				if ( sum < k ) chk++;
			}
		}
		else
		{
			int sum = 0;
			for ( i = 0; i < n; i++ ) sum += arr[i];
			if ( sum < k ) chk++;




		}
		cout << chk << "\n";
		T--;
	}




	return 0;
}