/*
Input:
1
6 6
2 4
3 4
5 1
5 2
6 3
6 1

Output:
6 5 3 2 4 1
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
vector<int> adj[MX];
vector<bool> vis(MX, false);
vector<int> ans;

void dfs(int u)
{
	vis[u] = true;
	for (int v : adj[u])
	{
		if (!vis[v])
			dfs(v);
	}
	ans.push_back(u);
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
	}

	for (int i = 1; i <= nodes; i++)
	{
		if (!vis[i])
			dfs(i);
	}
	reverse(ans.begin(), ans.end());
	for (int i : ans)
		cout << i << " ";
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
