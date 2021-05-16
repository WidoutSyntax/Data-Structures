/*
1
6 6
0 1
1 3
3 5
0 2
2 4
2 3

TC: O(V + E)
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

void BFS(vector<int> *adj, int u, vector<bool> &vis)
{
	queue<int> q;
	q.push(u);
	vis[u] = true;
	while (!q.empty())
	{
		int x = q.front();
		cout << x << " ";
		q.pop();
		for (int i = 0; i < adj[x].size(); i++)
		{
			if (!vis[adj[x][i]])
			{
				q.push(adj[x][i]);
				vis[adj[x][i]] = true;
			}
		}
	}
}

void solve()
{
	int nodes, edges;
	cin >> nodes >> edges;
	vector<int> *adj = new vector<int>[nodes];
	for (int i = 0; i < edges; i++)
	{
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	vector<bool> vis(nodes, false);
	for (int i = 0; i < nodes; i++)
		if (!vis[i])
			BFS(adj, i, vis);
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
