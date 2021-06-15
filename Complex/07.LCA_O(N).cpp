/*
Input:
9 8 2
1 2
1 3
2 4
2 5
4 6
4 7
6 9
7 8
9 5
3 6

Output:
2
1
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
vector<int> par(MX, -1), level(MX, -1);

void dfs(int u, int l, int p = -1)
{
    par[u] = p;
    level[u] = l;
    for (int to : adj[u])
    {
        if (to != p)
            dfs(to, level[u] + 1, u);
    }
}

int LCA(int a, int b)
{
    if (level[b] < level[a])
        return LCA(b, a);
    int diff = level[b] - level[a];
    while (diff--)
        b = par[b];

    if (a == b)
        return a;

    while (par[a] != par[b])
    {
        a = par[a];
        b = par[b];
    }

    return par[a];
}

void solve()
{
    int nodes, edges, queries;
    cin >> nodes >> edges >> queries;
    for (int i = 0; i < edges; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    dfs(1, 0, -1);

    for (int i = 0; i < queries; i++)
    {
        int a, b;
        cin >> a >> b;
        cout << LCA(a, b) << endl;
    }
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
