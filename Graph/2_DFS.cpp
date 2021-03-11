/*
1
6 6
0 1
1 3
3 5
0 2
2 4
2 3
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

void DFS(vector<int> *adj, int u, vector<bool> &vis)
{
	stack<int> s;
	s.push(u);
	vis[u] = true;
	while (!s.empty())
	{
		int x = s.top();
		cout << x << " ";
		s.pop();
		for (int i = 0; i < adj[x].size(); i++)
		{
			if (!vis[adj[x][i]])
			{
				s.push(adj[x][i]);
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
			DFS(adj, i, vis);
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