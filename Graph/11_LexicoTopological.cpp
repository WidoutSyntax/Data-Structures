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
5 2 6 1 3 4
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
vector<int> ans, indeg(MX, 0);
set<int> s;

void topo()
{
	while (!s.empty())
	{
		int x = *(s.begin());
		s.erase(s.begin());
		vis[x] = true;
		ans.push_back(x);
		for (int to : adj[x])
		{
			indeg[to]--;
			if (indeg[to] == 0 && !vis[to])
				s.insert(to);
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
		indeg[b]++;
	}

	for (int i = 1; i <= nodes; i++)
		if (indeg[i] == 0)
			s.insert(i);

	topo();

	if (ans.size() != nodes)
		cout << "Not possible";
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
