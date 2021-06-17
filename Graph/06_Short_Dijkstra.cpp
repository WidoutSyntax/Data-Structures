/*
1
5 5
1 2 5
1 3 2
3 4 1
1 4 6
3 5 5

Ouput:
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
int dist[MX];

void Djktras(int u)
{
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	dist[u] = 0;
	pq.push({0, u});
	while (!pq.empty())
	{
		pair<int, int> p = pq.top();
		pq.pop();
		int x = p.second, w = p.first;
        if (dist[x] < w)
            continue;
		for (int i = 0; i < adj[x].size(); i++)
		{
			int x1 = adj[x][i].second, w1 = adj[x][i].first;
			if (dist[x] + w1 < dist[x1])
			{
				dist[x1] = dist[x] + w1;
				pq.push({dist[x1], x1});
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
	Djktras(1);
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
