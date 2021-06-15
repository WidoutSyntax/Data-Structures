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
vector<vector<int>> lca;
vector<int> level(MX, -1);

void dfs(int u, int l, int p = -1)
{
    lca[u][0] = p;
    level[u] = l;
    for (int to : adj[u])
    {
        if (to != p)
            dfs(to, level[u] + 1, u);
    }
}

int LCA(int a, int b, int nodes)
{
    if (level[b] < level[a])
        return LCA(b, a, nodes);

    int h = log2(nodes);
    int diff = level[b] - level[a];

    while (diff > 0)
    {
        int i = log2(diff);
        b = lca[b][i];
        diff = diff - (1 << i);
    }

    if (a == b)
        return a;

    for (int i = h; i >= 0; i--)
    {
        if (lca[a][i] != -1 && lca[a][i] != lca[b][i])
            a = lca[a][i], b = lca[b][i];
    }

    return lca[a][0];
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

    int h = log2(nodes);
    lca.resize(nodes + 1);
    for (int i = 0; i < nodes + 1; i++)
        lca[i].resize(h + 1, -1);

    // dfs call to get level and lca table first column
    dfs(1, 0, -1);

    // populate lca table
    for (int j = 1; j <= h; j++)
    {
        for (int i = 1; i <= nodes; i++)
        {
            int par = lca[i][j - 1];
            if (par != -1)
                lca[i][j] = lca[par][j - 1];
        }
    }

    for (int i = 0; i < queries; i++)
    {
        int a, b;
        cin >> a >> b;
        cout << LCA(a, b, nodes) << endl;
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
