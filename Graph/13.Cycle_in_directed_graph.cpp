/*
Input:
5 5
1 2
2 3
3 4
4 1
1 5

Output:
Yes, cycle is present
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

const int MX = 1e5 + 5;
vector<int> adj[MX];
vector<bool> vis(MX, false), rec(MX, false);

bool isCycle(int u)
{
	if (!vis[u])
	{
		vis[u] = rec[u] = true;
		for (int to : adj[u])
		{
			if (!vis[to] && isCycle(to))
				return true;
			else if (rec[to])
				return true;
		}
	}
	rec[u] = false;
	return false;
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
	}
	for (int i = 1; i <= n; i++)
	{
		if (!vis[i])
			if (isCycle(i))
			{
				cout << "Yes, cycle is present";
				return;
			}
	}
	cout << "Cycle is not present";
	cout << endl;
}

int32_t main()
{
	IOS();
	int t = 1;
	//cin >> t;
	while (t--)
	{
		solve();
	}
	return 0;
}
