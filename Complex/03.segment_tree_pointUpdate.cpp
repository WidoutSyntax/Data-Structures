/*
Input:
1
10 1
8 2 5 1 4 5 3 9 6 10
2 5

Output: 15
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
vector<int> v(MX), seg(4 * MX);

void build(int ind, int low, int high)
{
    if (low == high)
    {
        seg[ind] = v[low];
        return;
    }

    int mid = low + (high - low) / 2;
    build(2 * ind + 1, low, mid);
    build(2 * ind + 2, mid + 1, high);

    seg[ind] = seg[2 * ind + 1] + seg[2 * ind + 2];
}

int query(int ind, int l, int r, int low, int high)
{
    if (l <= low && high <= r)
        return seg[ind];
    if (l > high || r < low)
        return 0;
    int mid = low + (high - low) / 2;
    int left = query(2 * ind + 1, l, r, low, mid);
    int right = query(2 * ind + 2, l , r, mid + 1, high);
    return left + right;
}

void pointUpdate(int ind, int low, int high, int node, int add)
{
    if (low == high)
        seg[ind] += add;
    else
    {
        int mid = low + (high - low) / 2;
        if (node >= low && node <= mid)
            pointUpdate(2 * ind + 1, low, mid, node, add);
        else
            pointUpdate(2 * ind + 2, mid + 1, high, node, add);
        seg[ind] = seg[2 * ind + 1] + seg[2 * ind + 2];
    }
}

void solve()
{
    int n, q;
    cin >> n >> q;
    for (int i = 0; i < n; i++)
        cin >> v[i];

    build(0, 0, n - 1);

    for (int i = 0; i < q; i++)
    {
        int l, r;
        cin >> l >> r;
        cout << query(0, l, r, 0, n - 1);
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
