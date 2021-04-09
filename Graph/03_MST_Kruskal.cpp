/*
1
4 5
1 2 7
1 4 6
4 2 9
4 3 8
2 3 6

Ouput: 19
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
pair<int, pair<int, int>> p[MX];
int id[MX];

int root(int x)
{
	if (x == id[x])
		return x;

	return id[x] = root(id[x]);
}

void unionn(int x, int y)
{
	int p = root(x);
	int q = root(y);
	id[p] = id[q];
}

int kruskal(int m)
{
	int cost = 0;
	sort(p, p + m);
	for (int i = 0; i < m; i++)
	{
		pair<int, pair<int, int>> p1 = p[i];
		int w = p1.first, x = p1.second.first, y = p1.second.second;
		if (root(x) != root(y))
		{
			cost += w;
			unionn(x, y);
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
		p[i] = {w, {a, b}};
	}

	for (int i = 0; i < MX; i++) 
		id[i] = i;
	cout << kruskal(edges);
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
