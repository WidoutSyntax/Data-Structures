/*
Input:
1
4 4 1
1 1 2 2                  ----> y
3 3 4 4                 |
5 5 6 6                 |
7 7 8 8                 x
1 1 3 2

Output: 33

TC:
update      O(log(nm))
getSum      O(log(nm))
build fTree O(nm (log(nm)))
total = O((nm+Q)log(nm))

SC: O(nm)
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

int getSum(int x, int y, vector<vector<int>> &fTree)
{
    x++;
    y++;
    int sum = 0, xdash = x;
    while (xdash > 0)
    {
        int ydash = y;
        while (ydash > 0)
        {
            sum += fTree[xdash][ydash];
            ydash = ydash - (ydash & -ydash);
        }
        xdash = xdash - (xdash & -xdash);
    }
    return sum;
}

void update(int x, int y, int n, int m, int add, vector<vector<int>> &fTree)
{
    x++;
    y++;
    int xdash = x;
    while (xdash <= n)
    {
        int ydash = y;
        while (ydash <= m)
        {
            fTree[xdash][ydash] += add;
            ydash = ydash + (ydash & -ydash);
        }
        xdash = xdash + (xdash & -xdash);
    }
}

void construct(int n, int m, vector<vector<int>> &mat, vector<vector<int>> &fTree)
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            update(i, j, n, m, mat[i][j], fTree);
}

int ansQuery(int x1, int y1, int x2, int y2, vector<vector<int>> &fTree)
{
    return getSum(x2, y2, fTree) - getSum(x2, y1 - 1, fTree) - getSum(x1 - 1, y2, fTree) + getSum(x1 - 1, y1 - 1, fTree);
}

void solve()
{
    int n, m, q;
    cin >> n >> m >> q;
    vector<vector<int>> mat(n, vector<int>(m, -1));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> mat[i][j];

    vector<vector<int>> fTree(n + 1, vector<int>(m + 1, 0));
    construct(n, m, mat, fTree);

    for (int i = 0; i < q; i++)
    {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        cout << ansQuery(x1, y1, x2, y2, fTree);
    }
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
