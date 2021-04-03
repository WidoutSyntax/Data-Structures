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
vector<int> adj[MX];
vector<int> tin, low;
vector<bool> vis;
int timer;

void dfs(int u, int p = -1)
{
	vis[u] = true;
	tin[u] = low[u] = timer;
	timer++;
	for (int to : adj[u])
	{
		if (to == p) continue;
		if (vis[to])
		{
			//this edge is back edge
			low[u] = min(low[u], tin[to]);
		}
		else
		{
			//this edge is forward edge
			dfs(to, u);
			low[u] = min(low[u], low[to]);
			if (low[to] > tin[u])
				cout << u << " --> " << to << " is a bridge." << endl;
		}
	}
}

void solve()
{
	int nodes, edges;
	cin >> nodes >> edges;
	for (int i = 0; i < edges; i++)
	{
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	vis.assign(MX, false);
	tin.assign(MX, -1);
	low.assign(MX, -1);
	for (int i = 1; i <= nodes; i++)
	{
		if (!vis[i])
			dfs(i);
	}
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

/*
Input:
1
4 3
1 2
1 3
1 4

Output:
1 --> 2 is a bridge.
1 --> 3 is a bridge.
1 --> 4 is a bridge.
*/
