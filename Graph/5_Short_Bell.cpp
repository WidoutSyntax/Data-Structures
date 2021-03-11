/*
1
5 5
1 2 5
1 3 2
3 4 1
1 4 6
3 5 5

Output:
1 --> 1 = 0
1 --> 2 = 5
1 --> 3 = 2
1 --> 4 = 3
1 --> 5 = 7

*/
#include<bits/stdc++.h>
#define int long long
using namespace std;

void IOS()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
}

const int MX = 100005;
vector<pair<int, int>> adj[MX];
int marked[MX] = {0};
int dist[MX];

void Bell(int u, int nodes)
{
	dist[u] = 0;
	for (int i = 0; i < nodes - 1; i++)
	{
		for (int x = 1; x <= nodes; x++)
		{
			for (int j = 0; j < adj[x].size(); j++)
			{
				int x1 = adj[x][j].second, w1 = adj[x][j].first;
				if (dist[x] + w1 < dist[x1])
					dist[x1] = dist[x] + w1;
			}
		}
	}
}

void solve()
{
	int nodes, edges;
	cin >> nodes >> edges;
	for (int i = 0; i < edges; i++)
	{
		int a, b, w;
		cin >> a >> b >> w;
		adj[a].push_back({w, b});
		adj[b].push_back({w, a});
	}
	for (int i = 0; i < MX; i++)
		dist[i] = INT_MAX;
	Bell(1, nodes);
	for (int i = 1; i <= nodes; i++)
		cout << 1 << " --> " << i << " = " << dist[i] << endl;
	cout << endl;
}

int32_t main()
{
	IOS();
	int t;
	cin >> t;
	while (t--)
	{
		solve();
	}
	return 0;
}
