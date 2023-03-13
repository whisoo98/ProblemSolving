#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <climits>
typedef long long ll;
#define endl '\n';
#define INF INT_MAX
using namespace std;

class segtreem {
public:
		vector<ll> tree;
		int size;
		segtreem(int n)
		{
			for (size = 1; size < n; size *= 2);
			tree.resize(2 * size);
		}
		void update(int pos, ll x)
		{
			int index = size + pos - 1;
			while (index)
			{
                if(tree[index]==0) tree[index]=INF;
				tree[index] = min(tree[index],x);
				index /= 2;
			}
		}
		
        ll getMin(int pos, int left, int right, int start, int end)
		{
			if (left <= start && right >= end)
			{
				return tree[pos];
			}
			else if (right < start || left > end)
			{
				return INF;
			}
			else
			{
				int mid = (start + end) / 2;
				return min(getMin(2 * pos, left, right, start, mid),getMin(2 * pos + 1, left, right, mid + 1, end));
			}
		}
};

class segtreeM {
public:
		vector<ll> tree;
		int size;
		segtreeM(int n)
		{
			for (size = 1; size < n; size *= 2);
			tree.resize(2 * size);
		}
		void update(int pos, ll x)
		{
			int index = size + pos - 1;
			while (index)
			{
                
				tree[index]= max(tree[index],x);
				index /= 2;
			}
		}
		ll getMax(int pos, int left, int right, int start, int end)
		{
			if (left <= start && right >= end)
			{
				return tree[pos];
			}
			else if (right < start || left > end)
			{
				return 0;
			}
			else
			{
				int mid = (start + end) / 2;
				return max(getMax(2 * pos, left, right, start, mid),getMax(2 * pos + 1, left, right, mid + 1, end));
			}
		}
};

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int N, Q;
	cin >> N >> Q;
	segtreem sTm(N);
    segtreeM sTM(N);
	for (int i = 1; i <= N; i++) 
	{
		ll temp;
		cin >> temp;
		sTm.update(i, temp);
        sTM.update(i, temp);
	}
	for (int i = 0; i < Q; i++)
	{
		int a,b;
		cin >> a >> b;
		cout << sTm.getMin(1, a, b, 1, sTm.size) << " "<<sTM.getMax(1,a,b,1,sTM.size)<<endl;
	}
}