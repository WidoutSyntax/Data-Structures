/*
Input:
7 7
0 1
1 2
2 3
3 4
4 6
6 1
4 5

Output:
No

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

const int MX = 100005;
vector<int> adj[MX];
vector<int> color(MX, -1);

bool isBipartite(int u)
{
	queue<int> q;
	color[u] = 0;
	q.push(u);
	while (!q.empty())
	{
		int x = q.front();
		q.pop();
		for (int to : adj[x])
		{
			if (color[to] == -1)
			{
				color[to] = 1 - color[x];
				q.push(to);
			}
			else
			{
				if (color[to] != 1 - color[x])
					return false;
			}
		}
	}
	return true;
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
		adj[b].push_back(a);
	}

	string ans = "";
	for (int i = 1; i <= n; i++)
	{
		if (color[i] == -1)
		{
			if (isBipartite(i))
				ans = "Yes";
			else
			{
				ans = "No";
				break;
			}
		}
	}
	cout << ans;
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
