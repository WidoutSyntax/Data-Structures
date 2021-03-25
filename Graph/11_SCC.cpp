/*
Input:
1
5 6
1 4
1 3
2 4
3 4
4 5
5 1

Output:
2
1 5 4 3
*************
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
vector<int> adj[MX], t_adj[MX];
vector<bool> vis(MX, false);
vector<int> order, compo;

void dfs1(int u)
{
	vis[u] = true;
	for (int i : adj[u])
	{
		if (!vis[i])
			dfs1(i);
	}
	order.push_back(u);
}

void dfs2(int u)
{
	vis[u] = true;
	compo.push_back(u);
	for (int i : t_adj[u])
	{
		if (!vis[i])
			dfs2(i);
	}
}

void solve()
{
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		t_adj[b].push_back(a);
	}

	vis.assign(MX, false);
	for (int i = 1; i <= n; i++)
		if (!vis[i])
			dfs1(i);

	vis.assign(MX, false);
	for (int i = 0; i < n; i++)
	{
		int v = order[n - 1 - i];
		if (!vis[v])
		{
			dfs2(v);
			for (int vert : compo)
				cout << vert << " ";
			cout << endl;
			compo.clear();
		}
	}
	cout << "*************";
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
