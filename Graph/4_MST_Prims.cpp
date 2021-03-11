/*
1
4 5
1 2 7
1 4 6
4 2 9
4 3 8
2 3 6

Output: 19
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

int prims(int u)
{
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
	pq.push({0, u});
	int cost = 0;
	while (!pq.empty())
	{
		pair<int, int> p = pq.top();
		pq.pop();
		int x = p.second, w = p.first;
		if (marked[x])
			continue;
		cost += w;
		marked[x] = 1;
		for (int i = 0; i < adj[x].size(); i++)
		{
			if (marked[adj[x][i].second] == 0)
				pq.push(adj[x][i]);
		}
	}
	return cost;
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
	cout << prims(1);
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
