#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, X, Y, W;

vector<pair<int, pair<int, int>>> Edge; //{가중치, {부모,자식}}
vector<int> parent;
vector<long long> NodeNumber;
long long sum = 0;

int Find(int node)
{
	if (parent[node] == node)
		return node;

	return parent[node] = Find(parent[node]); // path compression
}

void Union(int a, int b, int pos)
{
	a = Find(a);
	b = Find(b);
	parent[b] = a;
	NodeNumber[a] += (NodeNumber[b]);
	/*if (a < b)
	{
		parent[b] = a;
		NodeNumber[a] += (NodeNumber[b]);
		//  sum += Edge[pos].first * NodeNumber[b];
	}
	else if (a > b)
	{
		parent[a] = b;
		NodeNumber[b] += (NodeNumber[a]);
		//sum += Edge[pos].first * NodeNumber[a];
	}*/
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	parent.resize(N + 1);
	NodeNumber.resize(N + 1);
	fill(NodeNumber.begin(), NodeNumber.end(), 1);

	for (int i = 1; i <= N; i++)
	{
		parent[i] = i;
		NodeNumber[i] = 1;
	}

	for (int i = 0; i < N-1; i++)
	{
		cin >> X >> Y >> W;
		Edge.push_back({ W, {X, Y} });
	}

	sort(Edge.begin(), Edge.end());

	int pos = N - 2;

	while (pos >= 0) //가중치 큰 순으로 Union하려면 뒤에서부터!
	{
		if (Find(Edge[pos].second.first) != Find(Edge[pos].second.second))
		{
			sum += Edge[pos].first * (NodeNumber[Find(Edge[pos].second.first)]) * (NodeNumber[Find(Edge[pos].second.second)]);
			//cout << sum << endl;
			Union(Edge[pos].second.first, Edge[pos].second.second, pos);
		}
		pos--;
		//cout << "!" << endl;
	}

	cout << sum;
}