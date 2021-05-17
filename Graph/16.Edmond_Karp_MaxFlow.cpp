/*
Input:
2
6 8 1 6
1 2 10
1 3 8
2 3 2
2 4 5
3 5 10
5 4 8
4 6 7
5 6 10
6 9 1 6
1 2 7
1 3 4
3 2 3
2 4 5
2 5 3
3 5 2
5 4 3
4 6 8
5 6 5

Output:
15
10

TC: O(V E^2)
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

int BFS(int s, int t, vector<int> adj[], vector<vector<int>> &cap, vector<int> &par)
{
	fill(par.begin(), par.end(), -1);
	par[s] = -2;
	queue<pair<int, int>> q;
	q.push({s, INT_MAX});

	while (!q.empty())
	{
		int curr = q.front().first, flow = q.front().second;
		q.pop();

		for (int next : adj[curr])
		{
			if (par[next] == -1 && cap[curr][next])
			{
				par[next] = curr;
				int newFlow = min(flow, cap[curr][next]);
				if (next == t)
					return newFlow;
				q.push({next, newFlow});
			}
		}
	}
	return 0;
}

int maxFlow(int s, int t, vector<vector<int>> &cap, vector<int> adj[], vector<int> &par)
{
	int flow = 0;
	int newFlow;
	while (newFlow = BFS(s, t, adj, cap, par))
	{
		flow += newFlow;
		int curr = t;
		while (curr != s)
		{
			int prev = par[curr];
			cap[prev][curr] -= newFlow;
			cap[curr][prev] += newFlow;
			curr = prev;
		}
	}
	return flow;
}

void solve()
{
	int n, m, s, t;
	cin >> n >> m >> s >> t;
	vector<int> adj[n + 1];
	vector<int> par(n + 1);
	vector<vector<int>> cap(n + 1, vector<int>(n + 1, 0));
	for (int i = 0; i < m; i++)
	{
		int a, b, w;
		cin >> a >> b >> w;
		adj[a].push_back(b);
		adj[b].push_back(a);
		cap[a][b] = w;
	}

	cout << maxFlow(s, t, cap, adj, par);
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
