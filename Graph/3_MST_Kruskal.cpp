/*
1
4 5
1 2 7
1 4 6
4 2 9
4 3 8
2 3 6
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

int root(int i)
{
	while (i != id[i])
	{
		i = id[i];
		id[i] = id[id[i]];
	}
	return i;
}

void unionn(int a, int b)
{
	int p = root(a);
	int q = root(b);
	id[p] = id[q];
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

	int cost = 0;

	sort(p, p + edges);
	for (int i = 0; i < edges; i++)
	{
		pair<int, pair<int, int>> p1 = p[i];
		int x = p1.second.first, y = p1.second.second;
		if (root(x) != root(y))
		{
			cost += p1.first;
			unionn(x, y);
		}
	}
	cout << cost;
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
